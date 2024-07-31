// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	// upcasting 활용 #1. 
	std::vector<Dog*>    v1; // Dog 객체 만 보관하는 컨테이너
	std::vector<Animal*> v2; // 모든 동물 객체 를 보관하는 컨테이너
							// 동종(동일 기반 클래스를 사용하는 타입)
							// 의 객체를 저장하는 컨테이너 만들기
}
