#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using F = Shape*(*)(); 

	std::map<int, F> create_function_map; 
public:

	void register_shape(int key, F f)
	{
		create_function_map[key] = f;
	}

	Shape* create(int type)
	{
		Shape* s = nullptr;

		auto it = create_function_map.find(type);

		if ( it != create_function_map.end() )
		{	
			s = it->second();
		}
		return s;
	}
};


class AutoRegister 
{
public:
	AutoRegister(int key, Shape*(*f)() )
	{
		ShapeFactory::get_instance().register_shape(key, f);
	}
};

// 도형 클래스를 만들때 반드시 필요한 규칙을 자동생성하는 매크로 제공
#define REGISTER(key, classname)						\
	static Shape* create() { return new classname; }			\
	inline static AutoRegister ar{key, &classname::create}; 

/*
// inline static 이 안되는 환경은 아래처럼 매크로 추가로 만들면 됩니다.
#define REGISTER_IMPL(key, classname)	\
	AutoRegister classname::ar(key, &classname::create);
*/

class Rect : public Shape
{
	REGISTER(1, Rect)
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};



class Circle : public Shape
{
	REGISTER(2, Circle)
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

class Triangle : public Shape
{
	REGISTER(3, Triangle)
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }
};

class Line : public Shape
{
	REGISTER(4, Line)
public:
	void draw() override { std::cout << "draw Line" << std::endl; }
};


int main()
{	
	ShapeFactory& factory = ShapeFactory::get_instance();

	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;
	
	
		if ( cmd > 0 && cmd < 8 ) 
		{
			Shape* s = factory.create(cmd);

			if ( s != nullptr )
				v.push_back(s);
		}
		
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();	
			}
		}
	}
}




