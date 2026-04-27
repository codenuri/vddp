#include <cstdlib>
#include <iostream>

// 해결책 #2. strategy 패턴 사용
// => 메모리 할당/해지 전략을 다른 클래스로 분리
// => vector 뿐 아니라 모든 컨테이너가 사용 가능하게

// 메모리 할당기의 인터페이스를 먼저 설계
template<typename T>
struct IAllocator
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* p, std::size_t sz) = 0;
	virtual ~IAllocator() {}
};


template<typename T>
class vector
{
	T* buff = nullptr;
	int size;

	IAllocator<T>* alloc = nullptr;

public:
	vector(int sz, IAllocator<T>* a ) : size(sz), alloc(a) {}
	{
		buff = alloc->allocate(sz);
	}
	~vector()
	{
		alloc->deallocate(buff, size);
	}
};

// 이제 컨테이너에서 사용할 다양한 메모리 할당기를 제공하면 됩니다.
template<typename T> 
class MallocAllocator : public IValidator<T> 
{
public:
	virtual T* allocate(std::size_t sz) 
	{
		void* p = malloc(sizeof(T)*sz);
		return static_cast<T*>(p);
	}
	virtual void deallocate(T* p, std::size_t sz)
	{
		free(p);
	}	
};
int main()
{
	MallocAllocator<int> ma;

	vector<int> v(4, &ma);
}
