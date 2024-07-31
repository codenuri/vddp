// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하고
//         어디서든지 동일한 방법으로 접근 가능한 것

// => 결국 전역변수와 유사한 특징을 가지게 됩니다.
// => 전역변수는 좋은 코딩 스타일이 아닙니다.
// => 그래서 싱글톤 패턴에 대한 비판도 많이 있습니다.

// 아래 코드가 "mayer's singleton" 입니다.
// => "effective-C++" 책의 저자인 "scott-mayer" 가 처음 제안한 코드

class Cursor
{
	// 규칙 #1. 생성자를 private 에
private:
	Cursor() {}

	// 규칙 #2. 컴파일러에게 복사생성자를 만들지 말라고 지시
	Cursor(const Cursor&) = delete; // C++11 함수 삭제 문법
	Cursor& operator=(const Cursor&) = delete;
									// 관례적으로 복사를 삭제하면
									// 대입도 삭제 합니다.



	// 규칙 #3. 오직 한개의 객체를 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& get_instance()
	{
		static Cursor instance;  // static 지역변수가 핵심
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c3 = c1; // 복사생성자를 사용해서 객체 생성
					// 복사생성자는 사용자가 만들지 않으면 컴파일러가 제공
					// => 이렇게도 만들수 없어야 합니다
}








