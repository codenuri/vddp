// 3_가상함수1-1.cpp
#include <iostream>

class Animal
{
public:
	// non-virtual : static binding. 컴파일러가 결정해 달라.
	//				 포인터 타입으로 결정				
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 


	// virtual : dynamic binding. 실행시간에 메모리 조사후 호출
	//							실제 객체의 함수 호출. 
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; } 
};

class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; } 
	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; } 
};
int main()
{
	Animal a; 
	Dog d;    
	Animal* p = &d; 

	p->cry1(); // static binding. Animal Cry1
	p->cry2(); // dynamic binding Dgog Cry2
}

// godbolt.org 사이트
// => 다양한 프로그래밍 언어의 컴파일 결과(기계어, 어셈블리) 확인 가능한 사이트
