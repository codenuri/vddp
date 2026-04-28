#include <iostream>

class Cursor
{	
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;				
	Cursor& operator=(const Cursor&) = delete;	
	
public:
	// 아래 함수는 멀티스레드 환경에서 안전할까요 ?
	// => 오직 한개의 객체가 안전하게 생성자가 호출됨을 보장할수 있을까요 ?
	// => 안전합니다. 아래 코드는 자동으로 동기화 됩니다.
	// => 그래서 이 모델은 안전합니다.
	// => C++11 에서 언어 규칙으로 포함, 
	//    C++11 이후 모든 C++ 컴파일러에서 아래 코드는 안전
	//    현재 코드는 godbolt.org 에 넣어 보세요. 
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
}


