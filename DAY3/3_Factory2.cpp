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

	// 자신의 객체를 만드는 static 멤버 함수가 아주 유용하게 사용됩니다.
	static Shape* create() { return new Rect; }
};

// Rect 객체를 만드는 2가지 방법
// 1. Rect* rc = new Rect;
// 2. Rect* rc = Rect::create();





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

		if ( cmd >= 1 && cmd <= 8 ) 
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




