// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	std::vector<Dog*>    v1;	// Dog 타입의 객체만 보관 가능한 컨테이너
	std::vector<Animal*> v2;    // 동종을 보관 가능한 컨테이너
								// (동일 기반 클래스를 사용하는 타입들.. 모든 동물)

	// upcasting 장점(활용) #1.
	// => 동종을 보관하는 컨테이너 만들기 							
}
