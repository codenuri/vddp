#include <iostream>
#include <mutex>

// CRTP : Curiosly Recurring Template Pattern 
// => 기반 클래스 만들때 미래에 만들어질 파생 클래스 이름을 사용할수 있게하는기술
// => 원리는 템플릿 인자를 통해서 전달하는것

// 요즘 C++ 진영에서 아주 널리 사용하는 디자인 기술
// => C++20 의 "Range" 라이브러리가 이 기술로 설계됨

// github.com/aosp-mirror      <= 안드로이드 소스 코드

// libutils 에서 "include/utils" 선택후, Singleton.h 열어 보세요


template<typename T>
class Singleton
{
protected:
	Singleton() {}
	Singleton(const Singleton&) = delete; 
	Singleton& operator=(const Singleton&) = delete;

	static T* sinstance;	  // <==
	static std::mutex mtx;
public:
	static T& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if ( sinstance == nullptr )
			sinstance = new T;

		return *sinstance;
	}
};
template<typename T> T* Singleton<T>::sinstance = nullptr; 
template<typename T> std::mutex Singleton<T>::mtx;

// Mouse 클래스도 위와 같은 싱글톤 모델로 하고 싶다.
class Mouse : public Singleton< Mouse >
{

};


int main()
{
	Mouse& c1 = Mouse::get_instance();

}








