#include <iostream>

// 핵심
// => C++로 프로그램 작성시
// => 상속 문법을 사용하게 된다면
// => 반드시 기반 클래스 소멸자를 virtual 로 해야 합니다.!!! 외워야 합니다. 아주 중요. 

class Base
{
public:
//	~Base() {}
	virtual ~Base() {}  // 가상 소멸자 문법 
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
	delete p;	
	// 컴파일러는 p가 Base 라는 것만 알고 있으므로
	// Base 클래스의 소멸자를 조사(Derived 의 소멸자가 아닌)해서 가상인지 확인
}