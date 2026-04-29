#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 아래 2줄은 새로운 도형(Triangle) 이 추가되면 변경(추가)되어야 합니다.
		// => OCP 만족 못함
		if (cmd == 1) v.push_back(new Rect);		
		else if (cmd == 2) v.push_back(new Circle);
		
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();	// 다형성 사용. 
								// 새로운 도형이 추가(변경)되어도 변경될 필요 없다.
								// OCP 만족
			}
		}
	}
}




