#include <iostream>

// 핵심 : static_cast 와 dynamic_cast 의 차이점.
// 컴파일 시간 캐스팅
// 실행시간 캐스팅 

// 처음 배우면 dynamic_cast 가 좋아 보이지만!!
// => 좋은 디자인 에서는 "dynamic_cast" 는 되도록 사용하지 말자!  입니다.
// => 오후 수업부터 등장.. 

class Animal
{
public:
	int age;

	virtual ~Animal() {}  // 가상 소멸자 문법 - 가상함수 설명에서 보다 자세히 

	// 가상함수가 한개 이상 있으면
	// => 가상함수 테이블이 만들어 지고
	// => 그안에 타입 정보도 포함
	// => 따라서 dynamic_cast 사용가능 
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

	// 핵심 #2. dynamic_cast
	// => 실행시간 캐스팅 이라는 의미로 "dynamic_cast"
	// => 실행시간에 p 가 가리키는 곳이 Dog 가 맞는지 확인한후 캐스팅
	// Dog 가 아니라면 : 0 반환
	// Dog 가 맞다면   : 주소 반환
	Dog* pd2 = dynamic_cast<Dog*>(p);

	std::cout << pd2 << std::endl;

	// dynamic_cast 를 사용하려면
	// => 각 객체는 자신이 무슨 타입인지 타입정보를 보관해야 한다.
	// => C++에서는 타입정보가 가상함수 테이블에 놓이게 된다.
	// => 따라서, 가상함수가 있는 타입만 dynamic_cast 사용가능. 
}
