#include <iostream>

// meyer's 싱글톤 코드를 자동 생성하는 매크로
#define MAKE_SINGLETON(classname) 						\
private:												\
	classname() {}										\
	classname(const classname&) = delete;				\
	classname& operator=(const classname&) = delete;	\
public:													\
	static classname& get_instance() 					\
	{													\
		static classname instance;						\
		return instance;								\
	}


class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}