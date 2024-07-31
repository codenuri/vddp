#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// override : 기반 클래스 함수를 파생 클래스가 다시 만드는 것
	void cry() { std::cout << "Dog Cry" << std::endl; } 
};
int main()
{
	Animal a; a.cry(); // Animal Cry
	Dog d;    d.cry(); // Dog Cry

	Animal* p = &d; 

	p->cry();

	// C++, C# : Animal Cry
	// Java, Python, Swift, Objective-C 등 대부분의언어 : Dog Cry
}

// p->cry() 를 어떤 함수로 연결할것인가 ?
// => 함수 바인딩이라고 합니다.

// 1. static binding : 컴파일 할때 컴파일러가 함수 호출을 결정
//				   핵심 : 컴파일러는 p가 가리키는 개체의 타입을 알수없다
//				   컴파일러가 유일하게 아는 것은 p 자체가 "Animal*" 라는것
//				   Animal Cry
// 
// 논리적이지 않지만 빠르다.
// C++, C#의 기본 바인딩.

// 2. dynamic binding : 컴파일 할때는 p 가 가리키는 곳을 조사하는 
//					기계어 코드 생성.
//					실행시 메모리 조사후 호출
//					p 가 Dog 객체를 가리켰다면 "Dog Cry" 호출
// 논리적이지만 느리다.
// Java, Python, Swift 등의 대부분의 객체지향 언어
// C++/C# 의 virtual function
