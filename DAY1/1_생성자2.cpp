#include <iostream>

class Base
{
public:
	Base(int a){ }
	~Base()    { }
};

// 아래 코드는 어디에서 왜 에러일까요 ?
// => 핵심은 기반 클래스에 디폴트 생성자가 없다는 것!!!
class Derived : public Base
{
public:				
	// 핵심 #1. 기반 클래스에 디폴트 생성자가 없다면
	// 반드시 파생 클래스에서 명시적으로 기반 클래스 생성자를 호출해야 합니다.	
	// 아래 코드는 에러	
//	Derived()		{ } // Derived()      : Base() { }
//	Derived(int a)	{ } // Derived(int a) : Base()

	Derived()	   : Base(0)	{ } 
	Derived(int a) : Base(a)	{ } 


	~Derived()		{ }
};
int main()
{

}
