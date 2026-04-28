#include <iostream>

// singleton1.cpp : 오직 한개의 객체를 static 지역변수로 생성 ( static storage 에 생성)
//					=> 시스템에 따라 static storage가 작을수 있고
//					=> static storage 변수는 실행파일에 포함될수도 있다.
// 					=> Cursor 의 크기가 크다면.. 다른 메모리가 좋을수도 있다.

// 아래 코드       : 오직 한개의 객체를 heap 에 생성

class Cursor
{
private:
	Cursor() {}
	
	Cursor(const Cursor&) = delete;				
	Cursor& operator=(const Cursor&) = delete;	

	// C++17 에서 추가된 inline static 을 사용하면 
	// => static 멤버 데이타 만들때 클래스 외부 선언이 없어도 됩니다.
	// => 단, visual studio 사용하시는 분은 언어 Option 에서 C++17로 변경해야 합니다.
	inline static Cursor* instance = nullptr;
public:
	static Cursor& get_instance() 
	{
		if ( instance == nullptr )
			instance = new Cursor;

		return *instance;
	}
};
//Cursor* Cursor::instance; // inline static 이 아닌 경우 이코드 필요.



int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}

