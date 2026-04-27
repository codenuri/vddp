#include <iostream>
#include <vector>

// 핵심 #11. 가상 함수 vs 순수 가상함수

class unsupported_operation{};

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

	// 가상 함수      : 파생 클래스가 override 하지 않으면 기본 구현 제공하겠다는 의도
	// 순수 가상 함수 : 파생 클래스가 반드시 override 해야 한다고 지시하는 것

private:
//	virtual void draw_imp() { std::cout << "draw Shape\n"; } // 논리적으로 잘못된 코드
	virtual void draw_imp() = 0;

public:
	// clone() 의 경우
	// 1. 순수 가상함수로 해도 좋습니다. 
	// => 그런데, 순수 가상함수가 많아지면 코드구현이 증가할수도 있습니다

	// 2. 또 다른 널리 사용되는 기술
	// => 자주 사용되는 함수가 아닌 경우 예외를 던지는 경우도 있습니다.

	// 기본 구현으로 예외 발생
	// 1. clone() 을 override 하지 않고 사용하면 예외 발생
	// 2. clone() 을 override 하지 않고 사용도 안하면 ok
	// 3. clone() 을 override 하고 사용하면 ok
	// 즉, 사용해야 하는 도형만 override 하라는 것
	virtual Shape* clone()	{ throw unsupported_operation(); }


	// 또 다른 방법
	// C 스타일로 구현되지 않음을 나타내는 값을 반환
	// => get_area() 호출시 결과가 -1이 나오면 면적이 -1이 아니라
	//    면적 구할수 없음을 의미 한다고 약속
	virtual int get_area() { return -1; }
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
