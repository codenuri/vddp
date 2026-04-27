#include <iostream>
#include <vector>

// 핵심 #7.

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}

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
			for ( auto s : v ) 
			{
				s->draw(); 
			}
		}

		else if ( cmd == 0 )
		{
			std::cout << "몇번째 만든 도형을 복사할까요 >> ";

			int k;
			std::cin >> k;

			// k 번째 도형을 복사해서 새로운 도형을 생성후 v 에 추가

			// 어떻게 해야 할까요 ? k 번째 도형이 뭘까요 ?
		}
	}
}
