#include <iostream>
#include <mutex>

// CRTP : Curiously Recurring Template Pattern
// => 신기하게도 사용될수 있는 템플릿 패턴
// => 기반 클래스 만들때 미래에 만들어질 파생 클래스 이름을 사용하는 기술
// => 원리는 기반 클래스에서는 미래의 파생 클래스 이름을 템플릿 인자 "T" 로 해서 사용하고
//    파생 클래스 만들때 자신의 이름을 템플릿 인자로 전달하는 것

// => 1990년대 부터 사용되던 기술인데, C++20 이후 특히 많이 사용
// => GOF's 패턴이 아닌 "C++ Idioms" 중 한개. 

// github.com/aosp-mirror 에 접속해 보세요( 안드로이드 소스 코드 )
// platform system core 라는 레포지토리 선택
// libutils/include/utils/singleton.h 파일 열어 보세요


template<typename T>
class Singleton
{
protected:
	Singleton() {}
	
	Singleton(const Singleton&) = delete;				
	Singleton& operator=(const Singleton&) = delete;	

	inline static T* instance = nullptr;   // <=== 
	inline static std::mutex mtx;
public:
	static T& get_instance()    // <===
	{
		std::lock_guard<std::mutex> g(mtx); 

		if ( instance == nullptr )
			instance = new T;   // <== 

		return *instance;
	}
};

// Mouse 클래스도 위와 동일한 방식의 Singleton 으로 만들고 싶다
class Mouse : public Singleton< Mouse >
{
};
class Keyboard : public Singleton< Keyboard >
{
};


int main()
{
	Mouse& m1 = Mouse::get_instance();
	Mouse& m2 = Mouse::get_instance();
}

