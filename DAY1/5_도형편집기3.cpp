#include <iostream>
#include <vector>

// 핵심 #3.

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
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
			for ( auto s : v )  // A
				s->draw();      // B. error
		}
	}
}
// 위 코드는 어디에서 ? 왜 컴파일 에러 일까요 ?
// => A 부분에서 s 의 타입은 Shape*
// => 그런데, Shape에는 draw() 가 없다
// => 기반 클래스 타입의 포인터로 파생 클래스 고유 멤버 접근 안됨. 
// => B 에서 에러!!!

// 해결책은 뭘까요 ?
// => 다음소스에서!!

