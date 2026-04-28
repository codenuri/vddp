#include <iostream>
#include <mutex>

// RAII Idioms
// => Resource Acquision Is Initialization
//    자원 획득은 (자원관리객체가) 초기화 될때(생성자) 이다.
// => 자원의 해지를 강조하지 않고, 자원의 획득을 강조하는 이름
//    (자원 획득이 중요하고, 획득했다면 당연히 해지 하는 것이다. 관점인데..)
//    (실제로는 안전하게 해지 하자는 의미의 기술)

// => 자원의 관리는 "생성자/소멸자" 에 의존해야 한다.
// => C++에서는 RAII 가 테크닉으로 분류
// => Rust 언어는 모든 자원 관리는 "RAII" 사용 - 문법에 포함됨

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

		std::lock_guard<std::mutex> g(mtx); // 이미 표준에 위에서 만든것과 거의 유사한
											// std::lock_guard 가 있습니다.

//		lock_guard<std::mutex> g(mtx); // lock_guard 의 생성자와 소멸자를 생각해 보세요
										// 1. g 의 생성자에서 "mtx.lock()" 실행
										// 2. g 의 소멸자에서 "mtx.unlock()" 실행
										// => if ( ... ) return 등의 코드가 추가되어도 g의 소멸자는 호출됨
										//    mtx.unlock() 은 수행됨
										// => 함수 실행중 예외가 발생되어도 지역변수 g 의 소멸자는 호출되고
										//    catch 로 이동
										
										// 3. 함수 끝이 아닌 중간에 해지 하려면 {} 사용
										// {
										//   	lock_guard<std::mutex> g(mtx);
										//		...
										// }
//		mtx.lock();
		if ( instance == nullptr )
			instance = new Cursor;
//		mtx.unlock();

//  	if ( ... ) return;

		return *instance;
	}
};





int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}

