#include <iostream>

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};

class PhotoSticker : public IDraw
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};
//----------------------------------------




// 기능 추가 클래스는 공통의 특징을 가지는 경우가 많습니다.
// 기반 클래스로 제공하면 편리합니다

class Decorator : public IDraw 
{
	IDraw* origin; 
	// int x, y;
public:	
	Decorator(IDraw* o) : origin(o) {}

	void draw() { origin->draw();}
};

class Emoticon : public Decorator
{
public:
	Emoticon(IDraw* ps) : Decorator(ps){}
	
	void draw()	
	{ 
		std::cout << "&&&&&&&&&&&&&&&&&&&&\n";  
		Decorator::draw();					
		std::cout << "&&&&&&&&&&&&&&&&&&&&\n";  
	}
};
class Frame : public Decorator
{
public:
	Frame(IDraw* ps) : Decorator(ps){}
	
	void draw()	
	{ 
		std::cout << "====================\n";  
		Decorator::draw();					
		std::cout << "====================\n";  
	}
};

int main()
{
	PhotoSticker ps;	
	ps.take();	
	ps.draw();	

	Emoticon e(&ps); 
	e.draw();		 

	Frame f( &e );	 
	f.draw();	 	 

}

