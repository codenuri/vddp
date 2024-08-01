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


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int key)
	{
		Shape* s = nullptr;

		if      ( key == 1) s = new Rect;
		else if ( key == 2) s = new Circle;

		return s;
	}
};



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if ( cmd >= 1 && cmd <= 8 ) // 1 ~ 8 번을 도형 번호로 예약
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




