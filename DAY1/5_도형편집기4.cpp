#include <iostream>
#include <vector>

// #1. 모든 파생 클래스의 공통의 특징은 반드시 기반클래스에도 있어야 한다.
//     (문법이 아닌 디자인 원칙)
//    그래야, 기반 클래스 포인터로 해당 특징을 사용할수 있다.


// #2. 기반 클래스 함수중 파생 클래스가 override 하게 되는 것은 
//     "virtual" 이어야한다.

class Shape 
{
	int color;
public:
	virtual ~Shape() {}

	// 아래 함수는 virtual 로 할까요 ? non-virtual 로 할까요 ?
	// => 파생 클래스가 override 할 필요 없다. - non-virtual
	// => virtual 로 해도 되지만 "느리다!!"
	void set_color(int c) { color = c;}

	// 각 도형마다 면적을 구하는 방식은 다르다!!
	// => 파생 클래스가 override 해야 한다.
	// => virtual!!!
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
	}
}


