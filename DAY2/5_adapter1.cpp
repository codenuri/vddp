#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.

// TextView : 문자열을 보관하고 있다가 화면에 이쁘게 출력해주는 클래스

class TextView
{
	std::string data;
	// font 종류, 크기, 기울기, 색상. 
public:
	TextView(const std::string& s) : data(s) {}

	// 아래 함수가 문자열을 화면에 이쁘게 출력하는 함수 
	void show() { std::cout << data << std::endl; }
};




//=================================================
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// 도형 편집기 예제에서, "Rect", "Circle" 외에 "문자열"을 다루는 클래스도 필요 하다
// 여기에서 "TextView" 를 사용할수 없을까 ?
// => 그대로 사용할수는 없다.
// => "TextView" 는 Shape로 부터 상속받지 않았고, draw() 함수 도 없다. 

// 사용할수 있도록 변경해 봅시다.
class Text : public TextView, public Shape 
{
public:
	Text(const std::string& s) {}

	
};

int main()
{
	std::vector<Shape*> v;
}







