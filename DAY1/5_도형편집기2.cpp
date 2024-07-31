#include <iostream>
#include <vector>

class Shape 
{
	int color;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n";}
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n";}
};

int main()
{
	std::vector<Shape*> v;

	while( 1 )
	{
		int cmd;
		std::cin >> cmd;
		if      ( cmd == 1 ) v.push_back( new Rect);
		else if ( cmd == 2 ) v.push_back( new Circle);
		else if ( cmd == 9 )
		{
			for ( auto s : v)
				s->draw();	// Error.
							// s 의 타입은 Shape* 인데
							// Shape 에는 draw 가 없다
		}
	}
}
// 위 코드는 어디서 ? 왜 ? 에러일까요 ?
// 최선의 해결책은 뭘까요 ?

