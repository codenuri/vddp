
#include <iostream>


class Cursor
{

private:
	Cursor() {}

	Cursor(const Cursor&) = delete; 
	Cursor& operator=(const Cursor&) = delete;
								

public:
	// 아래 코드는 멀티 스레드 환경에 안전할까요 ?
	// => C++11 부터 안전합니다.
	// => 생성자 호출이 동기화 됩니다.
	// => 동기화 방법은 "spin lock(busy wait)" 입니다.!!
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

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;


}








