#include <iostream>
#include <mutex>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete; 
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;	
	static std::mutex mtx;
public:
	static Cursor& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if ( sinstance == nullptr )
			sinstance = new Cursor;

		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr; 
std::mutex Cursor::mtx;

// Mouse 클래스도 위와 같은 싱글톤 모델로 하고 싶다.
class Mouse 
{

};


int main()
{
	Mouse& c1 = Mouse::get_instance();

}








