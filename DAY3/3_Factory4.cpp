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


// 공장에 도형을 자동으로 등록하는 클래스
// => 생성자만 사용하기 위해 만든것
class AutoRegister 
{
public:
	AutoRegister(int key, Shape*(*f)() )
	{
		ShapeFactory::get_instance().register_shape(key, f);
	}
};

// 아래 한줄을 생각해 보세요
// => 전역변수의 생성자와 main 함수중 어느것이 먼저 실행될까요 ?
// 1. 모든 전역변수의 생성자가 호출된후
// 2. mai 함수 실행
// AutoRegister ar(1, &Rect::create);


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static 멤버 데이타의 특징을 생각하세요
	// => 1. 모든 객체가 공유
	// => 2. 객체를 한개도 만들지 않아도 프로그램 시작시 메모리에 존재(일종의 전역변수)
	//       => ar 의 생성자는 프로그램 시작시 호출
	//inline static AutoRegister ar(1, &Rect::create); // 클래스 안에서 객체 생성시 () 사용하면
													 // 함수선언와 헷갈려서 컴파일 에러
	inline static AutoRegister ar{1, &Rect::create}; // {} 초기화 사용
};

// "inline static AutoRegister ar" 의 의미
/*
						// Rect::ar 의 생성자 호출 
						// => 결국 Rect 라는 타입에 대해서 한번 호출
Rect* r1 = new Rect;	// Rect 생성자 호출
Rect* r2 = new Rect;	// Rect 생성자 호출
Rect* r3 = new Rect;	// Rect 생성자 호출
						// 즉, 생성자는 객체당 1번씩 호출

// C# 에는 static 생성자 문법이 있습니다.
class Car 
{
	public Car() {} // 일반 생성자
	static Car() {} // static 생성자
}

Car c1 = new Car(); // static 생성자
					// Car 일반 생성자
Car c1 = new Car(); // Car 일반 생성자
*/







class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	inline static AutoRegister ar{2, &Circle::create};
};

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	static Shape* create() { return new Triangle; }

	inline static AutoRegister ar{3, &Triangle::create};
};


// main 이 실행되기 전에 이미
// 1. Rect::ar 의 생성자 호출됨
// 2. Circle::ar 의 생성자 호출됨
// => 즉, 각 도형은 공장에 등록된 상태로
// => main 함수 실행
// 의미 : 각 도형 클래스가 자신을 공장에 등록하는 코드를 스스로 가지고 있는것

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




