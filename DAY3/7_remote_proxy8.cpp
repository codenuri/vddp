#include <memory>

int main()
{
	// C++ 표준에 이미 스마트 포인터가 있는데.. 그것을 사용하면 안되나요 ?

	std::shared_ptr<int> p1(new int); // 생성자에서 주소를 보관했다가
									  // 소멸자에서 delete 합니다

	std::shared_ptr<int> p2(load_proxy());
							// 소멸자에서 proxy 주소를 delete 합니다.
							// 즉, DLL 에서 new 한것을 
							//     exe 가 delete 한것!!!

							// 우리가 필요한 것은 소멸자에서 delete 가아닌
							// Release()를 호출하는 것

							// 그래서 별도의 sp 를 만든 것.
}
