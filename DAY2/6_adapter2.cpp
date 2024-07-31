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

// adapter 의 종류
// 클래스 어답터 : 클래스의 인터페이스를 변경
// 객체   어답터 : 객체의 인터페이스를 변경

class Text : public TextView, public Shape 
{
public:
	Text( const std::string& data) : TextView(data) {}

	void draw() override 
	{
		TextView::show();
	}
};

// 객체 어답터를 만들려면 내부적으로 
// 외부에 이미 생성된 객체를 가리키는 포인터가 있어야 합니다.
class ObjectAdapter : public Shape 
{
	TextView* tv; 	// 핵심 : 포인터(또는 참조) 멤버 데이타
					// 외부에 이미 생성된 객체를 가리키겠다는 의도.
public:
	ObjectAdapter( TextView* tv) : tv(tv) {}

	void draw() override 
	{
		tv->show();
	}
};



int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); 	// TextView : 클래스
							// tv       : 객체

	// 이미 생성된 객체 tv 를 vector 에 넣을수 있을까 ?
//	v.push_back( &tv ); // error
	v.push_back( new ObjectAdapter(&tv) ); // ok
}







