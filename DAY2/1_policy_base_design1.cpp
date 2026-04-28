#include <iostream>
#include <vector>

// STL 에 사용시, 사용자 정의 메모리 할당기를 만들려면
// => 약속된 규칙을 반드시 지켜야 합니다
// #1. allocate/deallocate 함수를 반드시 만들어야 합니다. 아래 코드 참고
// #2. #A 부분의 멤버 3개를 반드시 만들어야 합니다(관례적인 코드, 그냥 복사해서 사용하면됩니다.)


template<typename T> 
class debug_alloc
{
public:
	// #A
	using value_type = T;
	debug_alloc() {}			// 디폴트 생성자
	template<typename U> debug_alloc(const debug_alloc<U>&) {} // generic 생성자


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
		// 일부 컴파일러는 이순간 1바이트 메모리가 할당 되기도 합니다
		// ex) visual studio 2022 버전..



	std::cout << "-----------------" << std::endl;

	v.resize(4);	// 1. int 4개 크기의 메모리 할당

	std::cout << "-----------------" << std::endl;

	v.resize(8);	// 1. int 8개 크기의 메모리 할당 필요
					// 2. 4개 메모리 내용 => 8개 메모리에 복사
					// 3. 기존의 4개 메모리 제거 
	std::cout << "-----------------" << std::endl;
}	// <= v 가 사용하던 8개 메모리 해지
