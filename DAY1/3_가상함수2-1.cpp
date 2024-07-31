#include <iostream>

// 핵심 #1. 기반 클래스 소멸자는 기본적으로 "virtual" 로 하세요

// 핵심 #2. 단, Base* p 인 상태로 delete 하는 코드가 없다면
// => virtual 로 안해도 됩니다.
// => 단, 안전하게 하기 위해 소멸자를 protected 에 놓으세요
//    아래 코드 참고

// 구글 "C++ Core guideline" 검색후 1번째 링크

class Base
{
	// protected 소멸자의도
	// => Base*인 채로 delete 하지 못하게 하는 것
protected:
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
	Base* p = new Derived;
//	delete p;	// error. 소멸자가 protected

	delete static_cast<Derived*>(p);

}	
