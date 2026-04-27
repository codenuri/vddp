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
			}
		}
	}
}

