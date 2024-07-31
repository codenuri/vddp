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
			{
				// 해결책 #1. Shape* 타입인 s 를 Rect* 나 Circle* 로 
				// 캐스팅후 사용
				// => dynamic_cast 로 조사후 캐스팅

				if ( dynamic_cast<Rect*>(s) != nullptr) 
					static_cast<Rect*>(s)->draw();

				else if ( dynamic_cast<Circle*>(s) != nullptr) 
					static_cast<Circle*>(s)->draw();	
	
				// 위 코드는 새로운 도형(Triangle) 추가시
				// => 제어문이 한줄 추가되어야 합니다.
				// => OCP 를 만족하지 못하는 코드 
				// => 좋지 않은 디자인 !!
			}
		}
	}
}


