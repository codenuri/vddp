#include <iostream>
#include <string>
#include <vector>

class TextView
{
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}
	void show() { std::cout << data << std::endl; }
};

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

// Adaptor 의 종류
// 1. 클래스 어답터 : 클래스의 인터페이스를 변경
// 2. 객체 어답터   : 객체의   인터페이스를 변경

class Text : public TextView, public Shape      
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override { TextView::show(); }
};

// 위 Text 는 클래스 어답터
// 아래 코드가 객체 어답터
class ObjectAdaptor : public Shape 
{
	Shape* origin; // [핵심] 이미 생성되어 있는 객체를 가리키는 포인터(또는 참조)
public:
	ObjectAdaptor(Shape* s) : origin(s) {}

	void draw() override 
	{
		// ?
	 }
};


int main()
{
	std::vector<Shape*> v;

	v.push_back( new Text("hello") );


	TextView tv("hello");		// TextView : 클래스
								// tv       : 객체

	// 이미 생성된 TextView 의 객체 "tv" 를 v 에 넣을수 있을까요 ?
	v.push_back(&tv); // error. tv 는 Shape 에서 상속되지 않음. 



}




