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
	// => 정확히는 ~Base() 만 호출되고 있는 것
	Base* p = new Derived;
	delete p;	

	// 왜 소멸자가 호출되지 않는가 ?
	// delete p;	// 1. p->소멸자() 로 호출하고
					// 2. 메모리 해지

	// 1번에서
	// p->소멸자() 도 함수 호출 과정이므로 어떤 함수를 호출할지를 결정
	// => p 의 타입이 Base* 이므로 Base 선언을 조사해서 소멸자가 가상인지 아닌지 조사
    // Base 소멸자가 가상이면 "dynamic binding". 실제 객체의 종류에 따라 호출
	// Base 소멸자가 가상이 아니면 "static binding". 포인터 타입으로 함수 결정후  호출
}	
