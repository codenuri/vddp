#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }


	Shape* clone() override { return new Rect(*this); }
};





class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	Shape* clone() override { return new Circle(*this); }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map;
public:

	void register_shape(int key, Shape* sample)
	{
		prototype_map[key] = sample;
	}

	Shape* create(int key)
	{
		Shape* s = nullptr;

		auto it = create_map.find(key);

		if ( it != create_map.end() )
		{
			s = it->second->clone(); // 견본객체->clone()
		}

		return s;
	}
};



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 이제 제품을 공장에 등록하고 사용하면 됩니다.
	// => 아래 코드는 결국 공장에 클래스를 등록하는 의미 입니다.
	// => 객체를 만들기 위한 함수를 등록하므로
//	factory.register_shape( 1, &Rect::create );
//	factory.register_shape( 2, &Circle::create );

	// 이번에는 자주 사용되는 견본 객체를 등록해 봅시다.
	Rect* redRect = new Rect;	// 빨간색, 크기20, 두께10..등 복잡한설정이
								// 필요한 객체
	Rect* blueRect = new Rect;
	Circle* redCircle = new Circle;

	factory.register_shape(1, redRect);
	factory.register_shape(2, blueRect);
	factory.register_shape(3, redCircle);


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




