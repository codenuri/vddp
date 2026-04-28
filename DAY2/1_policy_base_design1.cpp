#include <iostream>
#include <vector>

template<typename T> 
class debug_alloc
{
public:
	using value_type = T;
	debug_alloc() {}
	template<typename U> debug_alloc(const debug_alloc<U>&) {}


	inline T* allocate(std::size_t sz) 
	{ 
		void* p = malloc(sizeof(T) * sz);

		printf("debug_alloc : allocate %p, %zd cnts\n", p, sz);
		return static_cast<T*>(p);
	}

	inline void deallocate(T* p, std::size_t sz) 
	{ 
		printf("debug_alloc : deallocate %p, %zd cnts\n", p, sz);
		free(p); 
	}	
};

int main()
{
	// std::allocator<int> : C++ 표준 메모리 할당기
	//						 내부적으로는 new/delete 로 메모리 할당

	// std::vector<int> v;	// std::vector<int, std::allocator<int>> v;	
	
	// 사용자 정의 메모리 할당기 사용하기
	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(4);

	std::cout << "-----------------" << std::endl;

	v.resize(8);

	std::cout << "-----------------" << std::endl;

}
