#include <iostream>
#include <mutex>

// RAII
// => Resource Acquision Is Initialization
// => 자원이 획득되는 것은 (관리객체)가 초기화 될때이다(생성자라는 의미)

// 자원의 할당과 반납은 생성자/소멸자에 의존해야 합니다.
template<typename T>
class lock_guard 
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock();}
	~lock_guard()             { mtx.unlock();}
};



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
		{
			std::lock_guard<std::mutex> g(mtx);
//			lock_guard<std::mutex> g(mtx); 	// 1. g의 생성자에서 mtx.lock()
											// 2. g의 소멸자에서 mtx.unlock()
											// 3. 실행중 예외등이 발생해도
											//    지역변수 g 는 안전하게 파괴됩니다.
											//	  => 소멸자가 호출된다는 의미
	//		mtx.lock();
			if ( sinstance == nullptr )
				sinstance = new Cursor;
	//		mtx.unlock();
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

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}








