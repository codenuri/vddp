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

	// 첫번째 호출 : if 문 2번 수행되는 오버헤드 있음( 필요없는 1번이 추가.)
	// 나머지 호출 : lock/unlock 이 필요 없음.

	// DLCP : Double Check Locking Pattern
	//        DLCO ( Optimization ) 이라고도 합니다.

	// 그런데, 2004년에 이 코드는 버그라는 논문 발문
	// => effective C++ 의 저자와 modern C++ design 책의 저자가 공통 발표
	// => 이유는 다음 소스
	static Cursor& get_instance()
	{
		if ( sinstance == nullptr )
		{
			mtx.lock();
			
			if ( sinstance == nullptr )
				sinstance = new Cursor;
			
			mtx.unlock();
		}

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








