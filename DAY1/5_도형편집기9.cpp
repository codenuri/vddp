#include <iostream>
#include <vector>

// 핵심 #11. 가상 함수 vs 순수 가상함수


class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c;}
public:
	void draw() 
	{ 
		std::cout << "Mutex.lock\n"; 
		draw_imp();		
		std::cout << "Mutex.unlock\n"; 
	}

private:
	virtual void draw_imp() 
	{	
		std::cout << "draw Shape\n"; 
	}

public:
	virtual Shape* clone()
	{
		return new Shape(*this);
	}
	
	virtual int get_area() { return 0; }
};



class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n"; }

	Shape* clone() override
	{
		return new Rect(*this); 
	}
};


class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Circle\n"; }

	Shape* clone() override
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
