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


