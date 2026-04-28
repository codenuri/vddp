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

	static Cursor* instance;
public:
	static Cursor& get_instance() 
	{
		if ( instance == nullptr )
			instance = new Cursor;

		return *instance;
	}
};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}

