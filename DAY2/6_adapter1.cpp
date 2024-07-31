#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.
// TextView : 문자열을 보관했다가 화면에 이쁘게 출력하는 기능 수행

class TextView
{
	std::string data;
	// font name, size, color, italic, bold 등의 수많은 멤버들..
public:
	TextView(const std::string& s) : data(s) {}

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

// 도형편집기 시스템에서 "Rect", "Circle" 뿐 아니라 문자열도 관리하고 싶다.
// => 예전부터 있던 "TextView" 를 여기서 사용할수 있을까 ?
// => 안된다..  시스템이 요구하는 요구조건을 만족하지 않는다.

// TextView 의 인터페이스(멤버 함수)를 시스템에 맞게 변경해주는 클래스를 만들자

// adapter 패턴 : 인터페이스의 불일치를 해결해는 패턴
//				  클래스의 인터페이스를 시스템이 요구하는 인터페이스로 변경
//				  (인터페이스 변경 => 함수 이름 변경)

class Text : public TextView, public Shape 
{
public:
	Text( const std::string& data) : TextView(data) {}

	// show() 라는 인터페이스(함수이름)을 
	// 시스템에 맞도록 변경(draw) 해주는 핵심 코드
	void draw() override 
	{
		TextView::show();
	}
};

int main()
{
	std::vector<Shape*> v;

	v.push_back( new Text("hello"));
	v[0]->draw();
}







