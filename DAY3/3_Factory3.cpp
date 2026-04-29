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

	// 자신의 객체를 만드는 static 멤버 함수는 아주 유용하게 사용됩니다.
	// => 반드시 이 코드의 장점을 이해해 두세요
	static Shape* create() { return new Rect; }
};

// Rect 객체를 만드는 2가지 방법
// 1. Shape* r1 = new Rect;		  // 외부에서 직접 new 사용. 클래스 이름을 반드시 알아야 한다
// 2. Shape* r2 = Rect::create(); // static 멤버 함수 사용
								  // 클래스 이름을 몰라도 "Rect::create" 의 함수 주소만 알아도된다
/*
// C++ 에서는 "클래스를 자료구조에 보관" 할수 없습니다.
v.push_back("Rect"); // 클래스를 보관하는 것이 아니라 문자열 "Rect" 보관한것
					 // 문자열 "Rect" 로 Rect 객체를 만들수 없습니다.

// 하지만, 함수 포인터는 자료구조에 보관할수 있습니다
v.push_back(&Rect::create);	// 객체 생성할수 있는 함수 주소 보관
							// 이 함수를 사용하면 언제라도 Rect 객체 생성 가능

*/







class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};

// 아래 ShapeFactory 는 새로운 도형이 추가되어도 수정될 필요 없습니다.
// => 단, 새로운 도형이 추가되면 공장에 등록(register_shape()) 하는 과정이 필요 합니다.
class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using F = Shape*(*)(); // Shape* create() 함수의 주소를 담는 함수 포인터 타입 F
						   // typedef Shape*(*F)() 와 동일

	std::map<int, F> create_function_map; // (도형번호, 생성함수) 의 쌍을 보관
public:
	// factory.register_shape(1, &Rect::create)
	// factory.register_shape(2, &Circle::create) 형태의 코드로 등록
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
			// it->first : 키값(도형 번호)
			// it->second : value(생성함수 주소)
			s = it->second();
		}
		return s;
	}
};

int main()
{	
	// #1. 공장을 만들고
	ShapeFactory& factory = ShapeFactory::get_instance();

	// #2. 공장에 제품(도형)을 등록합니다.
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




