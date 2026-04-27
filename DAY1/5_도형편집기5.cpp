#include <iostream>
#include <vector>

// 핵심 #5. 모든 도형(파생 클래스)의 공통의 특징은 반드시 기반 클래스에도 있어야 한다.
// => 문법적인 규칙이 아닌
// => 객체지향 디자인의 원칙

// 핵심 #6. 기반 클래스 멤버 함수중에서 파생 클래스가 override 하게 되는 것이 있다면
//         반드시 가상함수로 만들어야 한다.
// => 문법적 규칙이 아닌 
// => 디자인의 원칙


class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

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
				s->draw();  // Shape 에도 draw()가 있으므로 에러 아님.
			}
		}
	}
}
