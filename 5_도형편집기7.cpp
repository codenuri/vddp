#include <iostream>
#include <vector>

// 핵심 #9. template method 디자인 패턴
// => 기반 클래스에서 변하지 않은 공통의 알고리즘(순서)을 제공하고(public, non-virtual)
// => 변해야 하는 부분만 가상함수로 분리(private또는 protected, virtual)
// => 파생 클래스가 변해야 하는 것만 변경


class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() { return 0; }

	// 공통성과 가변성의 분리
	// => 변하지 않는 코드 내부에 있는 변해야 하는 부분은 분리되어야 한다.
	// => 변하는 부분을 별도의 가상함수로 분리한다
	
private:
	virtual void draw_imp() 
	{	
		std::cout << "draw Shape\n"; 
	}

public:
	void draw() 
	{ 
		std::cout << "Mutex.lock\n"; 
		draw_imp();		
		std::cout << "Mutex.unlock\n"; 
	}


	virtual Shape* clone()
	{
		return new Shape(*this);
	}
};



class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n"; }

	Shape* clone()
	{
		return new Rect(*this); 
	}
};


class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle\n"; }

	Shape* clone()
	{
		return new Circle(*this); 
	}
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
	
			v.push_back( v[k]->clone() ); 

		}
	}
}
