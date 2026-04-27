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

				Rect* r = dynamic_cast<Rect*>(s);

				if ( r != nullptr )
				{
					r->draw();
				}

				Circle* c = dynamic_cast<Circle*>(s);
				
				if ( c != nullptr )
				{
					c->draw();
				}

			}

		}
	}
}

