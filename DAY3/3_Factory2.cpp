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
// 새로운 도형이 추가되면 ShapeFactory 는 변경됩니다.
// => 그런데, ShapeFactory 한곳만 수정하면 됩니다.
// => 즉, ShapeFactory 의 도입으로 새로운 도형 추가시, 코드 수정을 최소화 할수 있습니다.
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
	
		// 아래 코드는 새로운 도형이 추가되어도 변경되지 않습니다.
		// => 그런데 ?? ShapeFactory 코드는 수정되지 않나요 ?
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




