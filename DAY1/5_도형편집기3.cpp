#include <iostream>
#include <vector>

// 핵심 #3.

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
			for ( auto s : v )
				s->draw();
		}
	}
}
// 위 코드는 어디에서 ? 왜 에러 일까요 ?

// 해결책은 뭘까요 ?

