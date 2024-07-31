#include <iostream>

// PhotoSticker 와, 기능 추가 객체는 공통의 인터페이스가 필요하다
struct IDraw 
{
	virtual void draw() = 0;
	virtual ~IDraw(){}
};

class PhotoSticker : public IDraw 
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};



class Emoticon : public IDraw
{
	IDraw* ps; 
public:
	Emoticon(IDraw* ps) : ps(ps) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&\n"; 
		ps->draw(); 
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&\n"; 
	}
};

class Border : public IDraw
{
	IDraw* ps; 
public:
	Border(IDraw* ps) : ps(ps) {}

	void draw()
	{
		std::cout << "=========================\n"; 
		ps->draw(); 
		std::cout << "=========================\n"; 
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	
	ps.draw();	

	Emoticon em(&ps); 
	em.draw();	

	Border bo(&em); 
	bo.draw();	
	
}
