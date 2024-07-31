// github.com/codenuri/vddp

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
	Dog d;

	Dog* p1 = &d; 	// ok
	
//	int* p2 = &d; 	// error
	
	// 핵심 1. 기반 클래스 포인터로 파생 클래스 객체의 주소를 담을수 있다.
	//											(를 가리킬수 있다)
	// "upcasting" 이라고 합니다.
	Animal* p3 = &d; // ok


	// 핵심 2. 컴파일러는 p3 가 가리키는 곳에 실제로 어떤 타입의 객체가 있는지는
	// 알수없다. (실행시 변경 가능하므로)

	//if ( 사용자입력 == 1) p3 = &a;  // 실행할때 변경됨

	// 핵심 3. 컴파일러는 p3 자체의 타입이 "Animal*" 라는 것만 알기 때문에
	// p3를 사용해서는 Animal 의 멤버만 접근 가능하다.
	p3->age = 10; 	// ok
//	p3->color = 10; // error

	// 핵심 4. p3 를 가지고 Dog 고유의 멤버의 접근하려면 캐스팅 해야 합니다.

	static_cast<Dog*>(p3)->color = 10; // ok
						// 단 이경우 p3가 가리키는 곳이 Dog 객체가 아니라면
						// "미정의동작(Undefined)" 발생
						// 잘못된 코드

}











