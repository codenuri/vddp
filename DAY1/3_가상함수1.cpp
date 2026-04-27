#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// function override : 기반 클래스 멤버 함수를 파생 클래스가 다시 구현을 제공하는 것
	void cry() { std::cout << "Dog Cry" << std::endl; } 
};
int main()
{
	Dog d;
	Animal* p = &d; 
	
	// p 자체의 타입 : Animal*
    // p 가 가리키는 객체의 타입 : Dog

	// 아래 코드는 어떤 함수를 호출할까요 ?
	// if( 실행시 사용자 입력 == 1 ) p = &animal;
	p->cry();	// 1. Animal Cry
				// 2. Dog Cry
}

// p->cry() 코드를 어떤 함수와 연결할것인가 ?
// => 함수 바인딩(function binding) 이라는 개념

// 1. static binding  : 컴파일 시간에 컴파일러가 어떤 함수를 호출할지 결정
//				        [핵심] 컴파일러는 p 자체의 타입(Animal*) 는 알수 있지만
//						       p 가 가리키는 대상체 타입은 알수 없다.
//						따라서 컴파일러가 함수를 결정하면 포인터 타입(Animal*) 으로 결정
//						Animal Cry 호출
// 빠르지만, 논리적이지 못하다. 
// C++/C# 의 기본 바인딩정책

// 2. dynamic binding : 컴파일 시간에 p가 가리키는 객체의 타입을 조사하는 기계어 코드 생성
//						실행시간에 기계어 코드 실행해서 객체의 종류에 따라 함수 결정
//						p 가 가리키는 곳에 Dog 가 있었다면 Dog Cry 호출
// 
// 느리지만, 논리적이다.
// Java, Python, Kotlin, Objective-C, swift 등의 대부분의 객체지향 언어. 
// C++/C#의 가상함수

// 즉, 
// C++/C# : 위 2개 바인딩 선택 가능
// Java, Python, Kotlin, Objective-C, swift : dynamic binding 만 가능
