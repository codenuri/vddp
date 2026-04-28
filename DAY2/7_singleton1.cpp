#include <iostream>

// 싱글톤 
// #1. 오직 한개의 객체만 존재하는 것.
// #2. 프로그램의 어디에서도 동일한 방법으로 객체에 접근 가능하게 하는 것

// 결국 "전역변수" 와 유사
// => 그런데, 전역변수는 나쁜 코드 로 취급 됩니다.
// => 그래서, 싱글톤도 "나쁜 패턴" 이다 라고 하는 경우도 있습니다
//    그래도, 여러곳에서 사용되고, 다양한 활용/응용이 존재 합니다.

class Cursor
{
	// 규칙 #1. 생성자를 private 에
private:
	Cursor() {}

	// 규칙 #2. 컴파일러에게 복사 생성자와 대입연산자를 만들지 말라고 요청
	Cursor(const Cursor&) = delete;				// C++11 함수 삭제 문법
	Cursor& operator=(const Cursor&) = delete;	// 복사생성자 삭제시 대입연산자도 삭제하는것이
												// 코딩 관례

	// 규칙 #3. 오직 한개의 객체를 만드는 static 멤버 함수
public:
	static Cursor& get_instance() 
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	// #1. private 생성자이므로 아래 처럼은 안됨
//	Cursor c1, c2; // error.

	// #2. 아래 처럼 만드는 것도 막아야 한다.(복사 생성자)
//	Cursor c = c1;	// 일반 생성자가 아닌 복사 생성자 호출
					// => 사용자가 만들지 않아도 컴파일러가 제공
					// => 컴파일러에게 만들지 말라고 요청해야 한다.
}

//-----------------------------
// 위 코드의 특징
// => 오직 한개의 객체를 "static 지역 변수" 로 만든 것

// => effective-c++ 책의 저자인 "scott-meyer" 가 처음 제안한 코드
// => 그래서 이름이 "meyer's singleton" 이라고 합니다.
// => C++ 진영에서 가장 좋은 싱글톤 구현 이라고 알려진 코드






