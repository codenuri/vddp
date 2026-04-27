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
	Dog d;
	Dog* p1 = &d; 		// ok
//	int* p2 = &d; 		// error

	// 핵심 #1. upcasting 개념
	// => 기반 클래스 타입의 포인터(참조)로 파생 클래스의 객체 주소를 담을수 있다
	// => 가능한 이유는 "메모리 그림" 을 생각하세요
	Animal* p3 = &d; 	// ok

	// 핵심 #2. 컴파일 시간에 컴파일러는 p3 가 가리키는 객체의 타입은 알수 없다
	// => p3는 변수 이므로 실행시간에 변경될수 있으므로
	// => 아래 예제 참고
//	Animal a;
//	if ( 사용자 입력 == 1 ) p3 = &a;

	// 핵심 #3. p3 를 사용해서는 
	// => Dog 고유의 멤버에 접근할수없다.
	// => Animal 로 부터 상속된 멤버만 접근 가능
	// 이유가 중요합니다.
	// C++ 은 static type check 언어 이므로
	// static  type check : 컴파일 시간에 타입을 확인하는 언어
	//						C++, C#, Java, Rust 
	// dynamic type check : 실행 시간에 타입을 확인하는 언어
	//						Python
	
	// p3 는 Animal* 타입 이므로
	// => p3 를 따라가면 Animal 멤버인 age 가 있다는 사실은 컴파일러가 보장 가능
	// => 하지만 Dog 고유 멤버인 color 가 있다고는 보장할수 없다.
	p3->age = 10;   // ok
	p3->color = 10; // error

	// 핵심 #4. p3 를 사용해서 Dog 고유 멤버에 접근하려면
	// => 컴파일러가 보장할수 없으므로
	// => 사용자가 책임지고 접근하겠다고 표시해야 합니다.
	//    캐스팅
	static_cast<Dog*>(p3)->color = 10;

	// => 단 이경우 p3 가 가리키는 곳이 Dog 객체가 아니라면
	//    UB(Undefined Behavior, 미정의 동작 발생), 잘못된 코드

}











