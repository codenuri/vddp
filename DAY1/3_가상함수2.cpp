#include <iostream>

class Base
{
public:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	// #1. 아래 코드는 아무 문제 없음
//	Derived d;

	// #2. 아래 코드도 아무 문제 없음
//	Derived* p = new Derived;
//	delete p;

	// #3. 아래 코드가 이번 예제의 핵심!!!
	// => Derived 소멸자가 호출 안됨.
	Base* p = new Derived;
	delete p;

}	
