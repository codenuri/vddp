#include <iostream>

class Animal
{
public:
	// non-virtual : C++ 기본 바인딩인 static binding 사용
	// => 포인터 타입으로 함수 호출 결정
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 
	
	// virtual function : dynamic binding 해달라는 의미
	// => 포인터 타입이 아닌, 포인터가 가리키는 실제 객체 타입을 실행시 조사후 호출해 달라.
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; } 
};
class Dog : public Animal
{
public:
	void cry1()         { std::cout << "Dog Cry1" << std::endl; } 
	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; } 
};

int main()
{
	Dog d;
	Animal* p = &d; 

	p->cry1();	// non-virtual : static binding   포인터 타입으로 결정. Animal Cry
	p->cry2();	// virtual     : dynamic binding  실제 객체 타입으로 결정. Dog Cry
}