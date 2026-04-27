#include <vector>
#include <iostream>


// template method, strategy : GOF's 디자인 패턴에 있는 23개 패턴중 하나..
//                             모든 객체지향 언어에서 사용하는 전통적인 디자인

// policy base design : C++ 진영에서만 사용되는 아주 유명한 기술
//		                GOF's 패턴에는 없음.
//                      C++ 표준 STL 라이브러리가 이 디자인을 아주 널리 사용하고 있음. 


int main()
{
//	std::vector<int> v; // 이 코드는 결국 아래와 동일합니다.
//	std::vector<int, std::allocator<int> > v; //
						//	즉, 메모리 할당/해지가 필요할때마다 std::allocator 를 사용하라는것

	std::vector<int, MallocAllocator<int> > v;  // 사용자가 만든 메모리 할당기를 
												// 사용하겠다는 것
												// "단위전략4.cpp" 에서 만든 것은
												// 부족한점이 있어서 error.

	std::cout << "---------------------" << std::endl;

	v.resize(4);

	std::cout << "---------------------" << std::endl;

	v.resize(8);

	std::cout << "---------------------" << std::endl;

}
