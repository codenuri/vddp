#include <iostream>
#include <vector>

// 핵심 #7. 디자인 패턴이란 ?
// => 1994 년 발간된 책의 제목
// => 4명의 개발자가 당시 유행하던 다양한 기법에다가 이름을 부여 한 것
// => 4명의 갱단(gangs). Gang's of four 라는 의미로 "GOF's Design Pattern"
// => 23개의 이름.

// 핵심 #8. prototype 패턴
// => 견본이 되는 객체를 먼저 생성하고, 복사본을 사용해서 새로운 객체 생성
// => clone() 가상함수
// => 3일차 오전에 더 좋은 예제등장. 


class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() { return 0; }
	virtual void draw() { std::cout << "draw Shape\n"; }

	// 자신의 복사본을 만드는 가상함수는 아주 널리 사용되는 좋은 기술입니다.
	virtual Shape* clone()
	{
		return new Shape(*this); // 나와 동일한 모양의 새로운 객체
	}
};



class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	Shape* clone()
	{
		return new Rect(*this); 
	}
};


class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

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

			// k 번째 도형을 복사해서 새로운 도형을 생성후 v 에 추가
			// 어떻게 해야 할까요 ? k 번째 도형이 뭘까요 ?

			// 방법 #1. dynamic_cast 로 조사하자
			// => OCP 를 만족할수 없는 좋지 않은 디자인 !
			/*
			if ( Rect* r = dynamic_cast<Rect*>(v[k]); r != nullptr )
			{
				v.push_back( new Rect(*r));
			}
			else if ( Circle* c = dynamic_cast<Circle*>(v[k]); c != nullptr )
			{
				v.push_back( new Circle(*c));
			}
			*/
			// 방법 #2. 다형성(Polymorphism)			
			v.push_back( v[k]->clone() ); // 다형성(가상함수) 사용
										  // k 번째 도형의 종류를 알필요 없다
										  // 새로운 도형이 추가되어도 수정되지 않는다
										  // OCP 만족

			// 아래 격언을 생각해 보세요
			// => Don't Ask Do It
			// => 물어보지 말고, 시켜라. 
		}
	}
}
