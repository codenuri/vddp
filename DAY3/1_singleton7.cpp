#include <iostream>
#include <mutex>

// 동기화!!

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete; 
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;	
	static std::mutex mtx;
public:

	// 아래 함수가 100번 호출된다고 생각해 보세요
	// 최초 호출 : 객체 생성.
	// 99번 호출 : 생성된 객체 반환만.  하지만 lock/unlock 수행됩니다.
	//							     성능 이슈
	static Cursor& get_instance()
	{
		mtx.lock();
		
		if ( sinstance == nullptr )
			sinstance = new Cursor;
		
		mtx.unlock();

		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr; 
std::mutex Cursor::mtx;




int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();


}








