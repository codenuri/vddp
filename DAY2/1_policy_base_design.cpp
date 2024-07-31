#include <iostream>
#include <vector>

// 사용자 정의 메모리 할당기
// 1. 반드시 템플릿일 필요는 없지만 다양한 타입에 대해 메모리 할당해야 하므로
//    일반적으로는 템플릿으로 작성

// 2. 반드시 약속된 규칙을 지켜야 한다

template<typename T> 
class debug_alloc
{
public:	
	// 규칙 #1. 아래 3개 필요 합니다. 관례적인 코드. 그냥 모양만 제공하면 됩니다.
	using value_type = T;
	debug_alloc() {}
	template<typename U> debug_alloc(const debug_alloc<U>&) {}


	// 규칙 #2. 아래 2개의 함수에서 메모리 할당/해지 방법을 제공하면 됩니다.
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
//	std::vector<int> v;	// std::vector<int, std::allocator<int>> v;	
	
	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(4); // 4개 크기의 메모리 할당

	std::cout << "-----------------" << std::endl;

	v.resize(8); // 1. 8개 크기 메모리 할당
				 // 2. 4개 버퍼 내용 => 8개 크기 버퍼에 복사
				 // 3. 4개 버퍼 제거

	std::cout << "-----------------" << std::endl;

}


// github.com/codenuri/vddp 
 
// 에서 DAY2.zip 받으시면 됩니다.







