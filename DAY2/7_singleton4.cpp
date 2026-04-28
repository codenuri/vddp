#include <iostream>
#include <mutex>

// 이번 예제는 "RAII" - 중요한 IDioms

// 아래 처럼 만들지 마세요 - 나쁜 코드
void func() 
{
	// 함수 윗부분에서 자원 할당

	// 함수 아래부분에서 자원 해지 - 나쁜 코드
}

// 좋은 코드는 다음 예제

class Cursor
{
private:
	Cursor() {}
	
	Cursor(const Cursor&) = delete;				
	Cursor& operator=(const Cursor&) = delete;	

	inline static Cursor* instance = nullptr;
	inline static std::mutex mtx;
public:

	static Cursor& get_instance() 
	{
		mtx.lock();

		if ( instance == nullptr )
			instance = new Cursor;
		/*
		// #1. 나중에 추가된 코드에서 실수 할수 있다
		if ( .... )
		{
			// unlock 을 하지 않고 return
			return;
		}

		// #2. 다양한 작업중에 예외가 발생할수 있다.
		foo(); // 이 함수에서 예외가 발생하면
			   // => 즉시 catch 로 이동
			   // => unlock 을 하지 않고 이동
		*/
		// 자원의 해지를 함수 아래 부분에서 하는 것은 나쁜 코드 입니다.
		// => 실행흐름이 아래 부분까지 도달하지 못할수 있습니다. 이유는 위 #1, #2 참고
		mtx.unlock();

		return *instance;
	}
};





int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}

