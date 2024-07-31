#include <iostream>

class Base
{
public:
//	~Base() {}
	virtual ~Base() {} // 핵심 : 기반 클래스의 소멸자는 
						//		반드시 virtual 로 해야 합니다.
						//		"가상 소멸자" 문법
						//      기반 클래스 소멸자가 virtual 이면
						//      모든 파생클래스 소멸자는 자동으로 virtual
};

class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d;  // OK. 아무 문제 없는 코드

//	Derived* p = new Derived;	// 생성자 호출
//	delete p;					// 소멸자 호출. 아무 문제 없는 코드

	// 아래 코드가 핵심 입니다.
	Base* p = new Derived;
	delete p;		// <== 이 순간을 생각해 보세요

	// 소멸자 호출도 함수 호출입니다.
	// => static binding 할지 dynamic binding 할지 결정되어야 합니다

	// 1. 컴파일러는 p가 Base* 라는 것만 알고 있으므로
	// 2. Base 선언을 보고 소멸자가 virtual 인지 아닌지 조사

	// non-virtual  : static binding    무조건 ~Base() 만 호출
	// virtual      : dynamic binding

}	
