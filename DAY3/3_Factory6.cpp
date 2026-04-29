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

int main()
{	
	ShapeFactory& factory = ShapeFactory::get_instance();

	// 아래 코드는 공장에 "클래스" 를 등록하는 의미
	// => 정확히는 객체를 만들기 위한 함수 포인터 등록
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);

	// 이번에는 공장에 "자주 사용되는 도형의 견본" 을 만들어서 등록해 봅시다.
	Rect* red_rect = new Rect;   // 빨간색 크기 10
	Rect* blue_rect = new Rect;  // 파란색 크기 20
	Circle* red_circ = new Circle;

	factory.register_shape(1, red_rect);
	factory.register_shape(2, blue_rect);
	factory.register_shape(3, red_circ);





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




