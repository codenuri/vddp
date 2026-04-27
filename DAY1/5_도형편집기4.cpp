#include <iostream>
#include <vector>

// 핵심 #4. 
// => 해결책 #1. dynamic_cast 를 사용한 캐스팅

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}
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
//				s->draw();  // error. Shape 에는 draw() 가 없다

				
				// C++17 에서 나온 새로운 if 문
				// if ( 초기화 구문; 조건식 )
				if ( Rect* r = dynamic_cast<Rect*>(s); r != nullptr )
				{
					r->draw();
				}			
				
				if ( Circle* c = dynamic_cast<Circle*>(s); c != nullptr )
				{
					c->draw();
				}
				
				// 새로운 도형(Triangle) 이 추가되면 아래 코드도 추가되어야 합니다.
				if ( Triangle* t = dynamic_cast<Triangle*>(s); Triangle != nullptr )
				{
					t->draw();
				}			

			}
		}
	}
}
// 위 방법이 좋은 디자인 일까요 ?
// => 나쁜 디자인!!

// 위 코드는 OCP 를 만족하지 않은 코드
// 기능 확장에 열려있고(Open, 새로운 클래스/모듈이 추가 되어도)
// 코드 수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않아야 한다.)
// 는 원칙(Principle)

// Open-Close principle 이라는 규칙.
// 위 코드는 OCP 를 만족할수 없는 좋지 않은 디자인
