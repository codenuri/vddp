#include <iostream>
#include <vector>

// #1. 디자인 패턴이란 ?
// => 1995년에 나온 책의 제목
// => 4명의 C++ 개발자가 지은 서적
// => 다양한 오픈소스가 사용하는 공통의 기법에 "이름" 을 부여 한것
//    23개의 이름 부여!
// => 4명의 갱단( Gang's Of Four) 해서 "GOF's Design pattern"


// #2. 아래 "예제에서" 파워포인트 처럼 "Undo/Redo" 기능을 넣고 싶다.
// => "Command" 패턴을 알면 됩니다 (3일차 배우게 됩니다.)


// #3. prototype 디자인 패턴
// => 객체를 만든후에 복사를 통해서 새로운 객체를 만드는 기법
// => clone() 가상함수
// => 3일차에 제대로 된 예제 나옵니다.


// #4. Refactoring 분야에서 유명한 용어 입니다. 의미를 이해해 보세요

// "Replace Conditional With Polymorphism"
// "제어문(if switch) 을 다형성(가상함수)로 변경해라"
// 도형편집기3.cpp 를 도형편집기4.cpp 로 변경해라


class Shape 
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() { return 0;}

	virtual void draw() { std::cout << "draw Shape\n";}


	// 자신이 복사본을 생성하는 가상함수는
	// 아주 유용하게 사용됩니다.
	virtual Shape* clone() { return new Shape(*this); }
};




class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n";}

	virtual Shape* clone() { return new Rect(*this); }	
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n";}

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

			// 방법 #2. 좋은 코드, 다형성!

			v.push_back( v[k]->clone() ); // 다형성!!
										  // k번째 도형이 어떤 도형인지
										  // 조사할 필요 없다
										  // 새로운 도형이 추가되어도
										  // 이 코드는 수정되지 않는다
										  // OCP 만족
		}
	}
}


