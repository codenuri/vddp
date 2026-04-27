#include <cstdlib>
#include <iostream>

// 변하는 것의 분리
// #1. 변하는 것을 가상함수로 분리
// #2. 변하는 것을 다른 클래스로 분리

// #2에서 변하는 것을 담은 정책 클래스를 어떻게 교체할까 ?
// => strategy 패턴 : 인터페이스기반 교체
// => policy base design : 템플릿 인자로 교체

// std::allocator<T> : C++ 표준이 제공하는 메모리 할당기
//					   내부적으로 new/delete 사용
template<typename T, typename Allocator = std::allocator<T> >
class vector
{
	T* buff = nullptr;
	int size;

//	MallocAllocator<T> alloc; // 클래스 이름을 직접 사용, 강한 결합, 교체 불가능

	Allocator alloc;	// 메모리 할당기. 어떤 할당기가 될지는
						// vector 사용 할때 2번째 템플릿 인자로 전달
public:
	vector(int sz) : size(sz)
	{
		buff = alloc.allocate(sz);
	}
	~vector()
	{
		alloc.deallocate(buff, size);
	}
};

// 이제 컨테이너에서 사용할 다양한 메모리 할당기를 제공하면 됩니다.
template<typename T> 
class MallocAllocator 
{
public:
	inline T* allocate(std::size_t sz) 
	{
		void* p = malloc(sizeof(T)*sz);
		return static_cast<T*>(p);
	}
	inline void deallocate(T* p, std::size_t sz)
	{
		free(p);
	}	
};
int main()
{
	// int : 저장할 요소의 타입
	// MallocAllocator<int> : 메모리 할당기 이름
	//vector<int, MallocAllocator<int> > v(4);
	vector<int> v(4); // 표준 할당기인 "std::allocator<T>" 사용
	
}
