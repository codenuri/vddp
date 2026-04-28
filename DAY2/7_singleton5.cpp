#include <iostream>
#include <mutex>

// RAII Idioms
// => 자원의 관리는 "생성자/소멸자" 에 의존해야 한다.

template<typename T>
class lock_guard 
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock();   }
	~lock_guard()             { mtx.unlock(); }
};


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
		lock_guard<std::mutex> g(mtx); // lock_guard 의 생성자와 소멸자를 생각해 보세요

//		mtx.lock();
		if ( instance == nullptr )
			instance = new Cursor;
//		mtx.unlock();

		return *instance;
	}
};





int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}

