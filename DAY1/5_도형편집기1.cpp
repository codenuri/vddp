#include <iostream>
#include <vector>

// #1. 각 도형을 타입으로 설계하면 편리합니다.

// #2. 모든 도형은 공통의 특징이 있다. 기반 클래스로 제공.
// => 기반 클래스가 있다면 모든 도형을 한개의 컨테이너에 보관할수 있다

class Shape 
{
	int color;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
	// int x, y, w, h; 생성자 등은 생략
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
//	std::vector<Rect*> v;
	std::vector<Shape*> v; // 모든 도형을 보관할수 있는 컨테이너..

}

