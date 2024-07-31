// 방법 #3. Policy Base Design 사용

// 함수 이름을 인터페이스로 약속하면
// => 모두 가상함수이다. 호출의 오버헤드가 있다.

// 함수이름을 문서화로 약속하면
// => 가상함수로 할 필요 없습니다.

#include <memory>

// std::allocator<T> :  C++ 표준 할당기. 내부적으로 new, delete 사용
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff = nullptr;
	int size;
	Alloc ax;	// 메모리 할당기. 앞으로 vector 의 모든 멤버 함수는
				// 이 객체의 멤버 함수에 의존해서 메모리 할당을 해야 합니다.
public:
	vector(int sz) : size(sz)
	{
		buff = ax.allocate(sz);
		//....
	}
	~vector()
	{
		ax.deallocate(buff, size);
	}
};


template<typename T>
class MyAllocator 
{
public:
	inline T* allocate(int sz)           
	{ 
		return static_cast<T*>(malloc(sizeof(T)* size));
	}
	inline void deallocate(T* p, int sz)  
	{ 
		free(p);
	}
};

int main()
{
	vector<int, MyAllocator<int> > v(4);
}
