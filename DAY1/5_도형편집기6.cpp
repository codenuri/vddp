#include <iostream>
#include <vector>

class Shape 
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() { return 0;}

	virtual void draw() { std::cout << "draw Shape\n";}
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
				s->draw();	
		}
		else if ( cmd == 8 )
		{
			std::cout << "몇 번째 도형을 복사할까요 >> ";
			int k;
			std::cin >> k;

			// k번째 도형의 복사본을 생성해서 v에 추가합니다.
			// 어떻게 구현해야 할까요 ?
			// k번째 도형은 어떤 도형일까요 ?
			
			// 방법 #1. dynamic_cast 로 조사후 복사본 생성
			// => OCP 를 만족하지 않은 좋지 않은 스타일!!
			if ( dynamic_cast<Rect*>(v[k]) != nullptr )
			{
				v.push_back( new Rect( * static_cast<Rect*>(v[k]) ) );
			}
			else if (Circle 조사)
			{
				// 위와 동일
			}
		}
	}
}


