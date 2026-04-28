#include <iostream>

// PhotoSticker 와 기능 추가 클래스(Decorator) 는 공통의 기반 클래스가 필요하다.
// => 그래야지, 중첩된 기능 추가가 가능
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
class Emoticon : public IDraw
{
//	PhotoSticker* origin; 
	IDraw* origin; 
public:
	Emoticon(IDraw* ps) : origin(ps){}
	
	void draw()	
	{ 
		std::cout << "&&&&&&&&&&&&&&&&&&&&\n";  
		origin->draw();					
		std::cout << "&&&&&&&&&&&&&&&&&&&&\n";  
	}
};
class Frame : public IDraw
{
	IDraw* origin; 
public:
	Frame(IDraw* ps) : origin(ps){}
	
	void draw()	
	{ 
		std::cout << "====================\n";  
		origin->draw();					
		std::cout << "====================\n";  
	}
};

int main()
{
	PhotoSticker ps;	
	ps.take();	
	ps.draw();	

	Emoticon e(&ps); // ps 에 Emoticon 기능을 추가해서
	e.draw();		 // 그리기

	Frame f( &e );	 // e 에 다시 Frame 기능을 추가해서
	f.draw();	 	 // 그리기.


}

