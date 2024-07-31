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

// 기능 추가 클래스는 공통의 특징이 있을수 있습니다.
// 기반 클래스로 제공합니다

class Decorator : public IDraw 
{
	IDraw* ps; 
	int x = 0;
	int y = 0; // 이모티콘이나 테두리를 그릴 위치
public:
	Decorator(IDraw* ps) : ps(ps) {}

	void draw() { ps->draw();}
};

class Emoticon : public Decorator
{
public:
	Emoticon(IDraw* ps) : Decorator(ps) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&\n"; 
		Decorator::draw(); 
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&\n"; 
	}
};
class Border : public Decorator
{
public:
	Border(IDraw* ps) : Decorator(ps) {}

	void draw()
	{
		std::cout << "=========================\n"; 
		Decorator::draw(); 
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
