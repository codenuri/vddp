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

	// 자신의 객체를 만드는 static 멤버 함수가 아주 유용하게 사용됩니다.
	// => Java 진영에서는 "static factory method" 라고 합니다.
	// => GoF's 패턴에는 없는 기법
	static Shape* create() { return new Rect; }
};

// Rect 객체를 만드는 2가지 방법
// 1. Rect* rc = new Rect;		// 객체를 만들기 위해 클래스 이름을 알아야 합니다.
// 2. Rect* rc = Rect::create();// 클래스 이름을 몰라도 함수의 주소만 알면 객체 생성가능.

// C++ 에서는 "클래스"를 자료구조에 보관할수 없습니다.
// v.push_back("Rect"); 	// 클래스가 아닌 문자열을 보관한것!!
							// 문자열로는 객체 생성이 안됩니다.

// 함수포인터는 자료구조에 보관 가능합니다
// v.push_back(&Rect::create); // 보관된 주소로 객체 생성 가능







class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape*(*)();

	std::map<int, CREATOR> create_map;
public:

	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}

	Shape* create(int key)
	{
		Shape* s = nullptr;

		auto it = create_map.find(key);

		if ( it != create_map.end() )
		{
			s = it->second(); 	// it->second 는 value 즉, 
								// 등록된 생성 함수
		}

		return s;
	}
};



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 이제 제품을 공장에 등록하고 사용하면 됩니다.
	factory.register_shape( 1, &Rect::create );
	factory.register_shape( 2, &Circle::create );


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




