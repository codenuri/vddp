#include <iostream>
#include <vector>
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
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// 도형 객체를 만드는 공장
class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int type)
	{
		Shape* s = nullptr;

		if      ( type == 1 ) s = new Rect;
		else if ( type == 2 ) s = new Circle;

		return s;
	}
};

int main()
{	
	ShapeFactory& factory = ShapeFactory::get_instance();


	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;
	
		if ( cmd > 0 && cmd < 8 ) // 1 ~ 7 를 도형의 번호로 예약
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




