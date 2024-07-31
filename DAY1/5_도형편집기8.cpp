#include <iostream>
#include <vector>


// #1. template method
// => 모든 파생 클래스에 공통적으로 적용된 규칙을 담은 메소드를 제공하는데
// => 변해야 하는 일부 내용만 가상함수화해서 파생 클래스가 변경할수 있게한다.
// => 가장 널리 사용되는 패턴
// => 변하는 것을 가상함수로!!

class Shape 
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c;}
	virtual int get_area() { return 0;}

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 변해야 하는 부분은 분리되어야한다
	// => 변하는 것을 별도의 가상함수로 분리 한다.

	virtual void draw_imp()
	{
		std::cout << "draw Shape\n";
	}
	void draw() 
	{
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}




	virtual Shape* clone() { return new Shape(*this); }
};




class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n";}

	virtual Shape* clone() { return new Rect(*this); }	
};

class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle\n";}

	virtual Shape* clone() { return new Circle(*this); }		
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

			v.push_back( v[k]->clone() ); 
		}
	}
}


