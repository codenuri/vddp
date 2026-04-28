#include <iostream>

// 이번 예제는 "스레드 동기화"

class Cursor
{
private:
	Cursor() {}
	
	Cursor(const Cursor&) = delete;				
	Cursor& operator=(const Cursor&) = delete;	

	inline static Cursor* instance = nullptr;
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

