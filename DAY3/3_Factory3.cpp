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

	// 자신의 객체를 만드는 static 멤버 함수는 아주 유용하게 사용됩니다.
	// => 반드시 이 코드의 장점을 이해해 두세요
	static Shape* create() { return new Rect; }
};

// Rect 객체를 만드는 2가지 방법
// 1. Rect* r1 = new Rect;		 // 외부에서 직접 new 사용
// 2. Rect* r2 = Rect::create(); // static 멤버 함수 사용













class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};


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




