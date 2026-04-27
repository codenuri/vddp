#include <iostream>

class Animal
{
public:
	int age;
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

//	Animal* p = &d; 
	Animal* p = &a; 

	// 현재 상태는 p 가 "Animal 객체" 를 가리키는 상태 

	// 핵심 #1. static_cast
	// => 컴파일 시간 캐스팅 이라는 의미로 "static_cast" 라는 이름 사용 
	// => 컴파일 시간에 컴파일러는 p가 가리키는 객체의 정확한 타입을 알수 없다
	//    if( 사용자 입력 == 1 ) p = &d; 같은 코드가 있다면 변경될수 있으므로
	// => 따라서, 컴파일러는 p의 대상을 조사할수 없으므로 아래 코드는 항상 컴파일된다.
	// => 그런데, 이때 pd 가 가리키는 곳이 Dog 가 아니면 UB 발생
	Dog* pd = static_cast<Dog*>(p);

	std::cout << pd << std::endl; // ok. 주소 잘 나옴!
//	pd->color = 10; // UB 잘못된 코드
	// 따라서 static_cast 는 p가 가리키는 객체가 Dog 라는 확신이 있을때 만 사용해야 한다.

	
}
