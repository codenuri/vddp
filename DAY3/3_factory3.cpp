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
			s = it->second(); 	
		}

		return s;
	}
};

// 공장에 자동으로 도형을 등록하는 클래스
struct AutoRegister 
{
	AutoRegister( int key, Shape*(*c)() )
	{
		ShapeFactory::get_instance().register_shape(key, c);
	}
};

// 전역변수의 생성자가 호출되는 시점을 생각해 보세요
//AutoRegister ar(1, &Rect::create);





class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static 멤버 데이타의 특징을 생각해 보세요
	// => 모든 객체가 공유
	// => 객체가 없어도 프로그램 실행시 static 멤버 데이타는 생성됩니다.
	// => ar 의 생성자는 main 함수 이전에 이미 호출됩니다.
	inline static AutoRegister ar{1, &Rect::create};
};

//			Rect::ar 의 생성자는 최초에 1회 호출.
// Rect* r1 = new Rect;	// 생성자 호출
// Rect* r2 = new Rect; // 생성자 호출
// Rect* r3 = new Rect; // 생성자 호출. 생성자는 "객체당 한번" 호출

// C# 코드
class Car 
{
	public Car() {} // instance 생성자
	static Car() {} // static 생성자
}

Car c1 = new Car; 	// static 생성자 호출
					// instance 생성자 호출
Car c2 = new Car;	// instance 생성자 호출



class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};






int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

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




