#include <iostream>
#include <vector>

// 핵심 #2. 기반 클래스인 Shape 도입
// 장점 #1. 모든 도형의 공통의 특징을 한곳에서 관리 가능
//      #2. 모든 도형을 같이 보관하는 컨테이너를 만들수 있다.

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
//	std::vector<Rect*> v;  // Rect 만 보관 가능한 컨테이너
	std::vector<Shape*> v; // 모든 도형을 보관할수 있는 컨테이너. 
}

