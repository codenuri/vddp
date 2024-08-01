#include <iostream>

struct A { int a; };
struct B { int b; };
struct C : public A, public B { int c; };

int main()
{
	// #1. 다중 상속과 upcasting 
	C c;

	A* pa = &c;
	B* pb = &c;

	std::cout << &c << std::endl;
	std::cout << pa << std::endl;
	std::cout << pb << std::endl;

	C* pc = static_cast<C*>(pb);
	std::cout << pc << std::endl;

	/*
	// #2. reinterpret_cast vs static_cast
	// c 의 주소가 1000 일때
	B* pb1 = &c;
	B* pb2 = static_cast<B*>(&c);
	B* pb3 = reinterpret_cast<B*>(&c);
	
	std::cout << "==============\n";
	std::cout << &c  << std::endl; // 1000 이면
	std::cout << pb1 << std::endl;
	std::cout << pb2 << std::endl;
	std::cout << pb3 << std::endl;
	*/
}
