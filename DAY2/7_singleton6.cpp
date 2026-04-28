#include <iostream>
#include <mutex>

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
		std::lock_guard<std::mutex> g(mtx); 

		if ( instance == nullptr )
			instance = new Cursor;

		return *instance;
	}
};

// Mouse 클래스도 위와 동일한 방식의 Singleton 으로 만들고 싶다
class Mouse 
{

};


int main()
{
	Mouse& m1 = Mouse::get_instance();
	Mouse& m2 = Mouse::get_instance();
}

