#include <iostream>
#include <mutex>

template<typename T>
class Singleton
{
private:
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

