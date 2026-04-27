#include <iostream>
#include <vector>

// 핵심 #10. 코드 정리및 생각해볼 문제


class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c;}
	virtual int get_area() { return 0; }
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

		// 생각해볼 문제 #1. 객체의 생성과정을 OCP 를 만족하게 할수 없을까 ?
		// => Triangle 이 추가되어도 아래 코드가 수정되지 않도록 !
		// => 추상 팩토리라는 디자인 패턴을 적용하면 됩니다(수요일 오전)

		// 생각해볼 문제 #2. Undo/Redo 기능을 만들려면 어떻게 해야 할까요 ?
		// => Undo/Redo 의 전형적인 기법이 있습니다.
		// => Command 패턴을 공부하면 됩니다.(수요일 오전)

		if      ( cmd == 1 ) v.push_back( new Rect );
		else if ( cmd == 2 ) v.push_back( new Circle );

		else if ( cmd == 9 )
		{
			for ( auto s : v ) 
			{
				s->draw();  // 다형성, OCP 만족, 좋은 코드
			}
		}
		else if ( cmd == 0 )
		{
			std::cout << "몇번째 만든 도형을 복사할까요 >> ";

			int k;
			std::cin >> k;	
			v.push_back( v[k]->clone() ); // 다형성, OCP 만족, 좋은 코드 

		}
	}
}
