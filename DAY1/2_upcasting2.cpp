#include <iostream>

class Animal
{
public:
	int age;

	virtual ~Animal() {} // 가상 소멸자, 다음시간에 자세히 설명
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Animal a;
	Dog    d;

	Animal* p = &d; 
//	Animal* p = &a; 

	// #1. static_cast
	// => 컴파일 시간 캐스팅
	// => 실제 객체가 Dog 인지 조사할수없다.
	// => 아래 코드는 항상 성공, 
	// => 하지만 p가 가리키는 곳이 Dog 가 아니었는데
	//    pdog1 을 사용하면 runtime 오류 입니다.
	Dog* pdog1 = static_cast<Dog*>(p);

	std::cout << pdog1 << std::endl;  // 실행해서 결과 확인해보세요

	// #2. dynamic_cast 
	// => 실행시간 캐스팅
	// => 실행 할때 p 가 가리키는 곳에 어떤 타입의 객체가 있는지 조사후
	// => 맞는 경우만 허용
	// => Dog 가 아닌 다른 타입의 객체가 있다면 0 반환

	// 단, dynamic_cast 를 사용하려면 반드시 한개이상의 가상함수가
	// 있는 타입만 가능.
	// => 타입 정보를 "가상함수테이블"에 보관하므로
	Dog* pdog2 = dynamic_cast<Dog*>(p);

	std::cout << pdog2 << std::endl;	
}
