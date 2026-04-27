#include <iostream>
#include <vector>

// 핵심 #5. 모든 도형(파생 클래스)의 공통의 특징(draw)은 반드시 기반 클래스(shape)에도 있어야 한다.
// => Shape 에도 draw() 필요
// => 문법적인 규칙이 아닌
// => 객체지향 디자인의 원칙

// 핵심 #6. 기반 클래스 멤버 함수중에서 파생 클래스가 override 하게 되는 것이 있다면
//         반드시 가상함수로 만들어야 한다.
// => 문법적 규칙이 아닌 
// => 디자인의 원칙
// => 아래 Shape 예제를 통해서 virtual 로 하는 것과 non-virtual 로 하는 것을 정확히 이해하세요

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	// 아래 멤버 함수는 virtual 로 할까요 ? non-virtual 로 할까요 ?
	// => 파생 클래스가 override 할 이유 없습니다. non-virtual!!
	void set_color(int c) { color = c;}

	// virtual ? non-virtual
	// => 대부분 도형을 면적을 구하는 방법이 다르다.
	// => 파생 클래스가 재정의해서 방법을 제공해야 한다.
	// => virtual 
	virtual int get_area() { return 0; }


	virtual void draw() { std::cout << "draw Shape\n"; }
};



class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};
class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw Triangle\n"; }
};
int main()
{
	std::vector<Shape*> v; 

	while(1) 
	{
		int cmd;
		std::cin >> cmd;

		if      ( cmd == 1 ) v.push_back( new Rect );
		else if ( cmd == 2 ) v.push_back( new Circle );

		else if ( cmd == 9 )
		{
			for ( auto s : v )  // Shape* s : v
			{
				s->draw();  // 다형성(Polymorphism)
							// => 동일한 표현식이 상황(실제 객체 종류)에 따라 다르게 동작하는것
							// => 장점 : 새로운 도형이 추가되어도 이 코드는 수정될 필요없다
							//			 OCP 를 만족하는 좋은 코드

				// 객체지향 언어의 3가지 핵심 특징
				// 1. 캡슐화(private, public)
				// 2. 상속(기존 클래스를 확장해서 새로운 타입 설계)
				// 3. 다형성(동일한 표현식이 상황(실제 객체 종류)에 따라 다르게 동작하는것)
			}
		}
	}
}
