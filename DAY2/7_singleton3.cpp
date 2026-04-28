#include <iostream>
#include <mutex>

// 이번 예제는 "스레드 동기화"

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
		
		mtx.unlock();

		return *instance;
	}
};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}

