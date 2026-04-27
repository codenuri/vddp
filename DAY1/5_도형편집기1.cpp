#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 객체지향 적으로 만드는 것을 생각해 봅시다.

// 핵심 #1. 모든 도형을 타입으로 설계하면 편리하다.

class Rect
{
	// x, y, w, h, 생성자 등은 생략, 
	// 가상함수 활용과 디자인만 집중
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};
int main()
{
	std::vector<Rect*> v;
}

