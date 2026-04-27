#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// function override : 기반 클래스 멤버 함수를 파생 클래스가 다시 구현을 제공하는 것
	void cry() { std::cout << "Dog Cry" << std::endl; } 
};
int main()
{
	Dog d;
	Animal* p = &d; 

	// p 자체의 타입 : Animal*
    // p 가 가리키는 객체의 타입 : Dog

	// 아래 코드는 어떤 함수를 호출할까요 ?
	p->cry();	// 1. Animal Cry
				// 2. Dog Cry
}


