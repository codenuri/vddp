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


// 공장에 도형을 자동으로 등록하는 클래스
// => 생성자만 사용하기 위해 만든것
class AutoRegister 
{
public:
	AutoRegister(int key, Shape*(*f)() )
	{
		ShapeFactory::get_instance().register_shape(key, f);
	}
};

// 아래 한줄을 생각해 보세요
// => 전역변수의 생성자와 main 함수중 어느것이 먼저 실행될까요 ?
AutoRegister ar(1, &Rect::create);




class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }
};







class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};




int main()
{	
	ShapeFactory& factory = ShapeFactory::get_instance();

	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);

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




