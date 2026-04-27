
//생성자1.cpp - 3page
#include <iostream>

// 핵심 : 생성자 호출의 정확한 원리를 알아 두세요

class Base
{
public:
	Base()     { std::cout << "Base()"    << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()"   << std::endl; }
};
class Derived : public Base
{
public:				
	// 사용자가 만든 코드		// 컴파일러가 변경한 코드
	Derived()				// Derived() : Base()	
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)			// Derived(int a) : Base()  <== 컴파일러가 추가한 코드는
	{													// 항상 Base 디폴트 생성자 호출
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 

		// Base::~Base()  <== 컴파일러가 추가한 코드입니다. 항상 Base 소멸자 호출
	}
};
int main()
{
//	Derived d1;
	Derived d2(5); // call Derived::Derived(int)

}

// 1. 파일을 프로젝트 빌드에서 제외/추가 하는 방법 알아 두세요
// 2. 빌드 하는 방법 : Ctrl + F5 
