#include <iostream>
#include <mutex>

class Singleton
{
private:
	Singleton() {}
	
	Singleton(const Singleton&) = delete;				
	Singleton& operator=(const Singleton&) = delete;	

	inline static Singleton* instance = nullptr;
	inline static std::mutex mtx;
public:
	static Singleton& get_instance() 
	{
		std::lock_guard<std::mutex> g(mtx); 

		if ( instance == nullptr )
			instance = new Singleton;

		return *instance;
	}
};

// Mouse 클래스도 위와 동일한 방식의 Singleton 으로 만들고 싶다
class Mouse : public Singleton
{

};


int main()
{
	Mouse& m1 = Mouse::get_instance();
	Mouse& m2 = Mouse::get_instance();
}

