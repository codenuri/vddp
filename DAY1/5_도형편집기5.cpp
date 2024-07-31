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
				s->draw();	// 다형성(Poliymorphism)
							// => 동일한 표현식이 상황(실제 객체의 종류)
							//    에 따라 다르게 동작하는 것

							// 새로운 도형(Triangle) 이 추가되어도
							// 이 한줄은 수정되지 않습니다.
							// OCP 를 만족하는 좋은 코드 입니다.

				// 객체지향언어의 3대 특징 : 캡슐화, 상속, 다형성

		}
	}
}


