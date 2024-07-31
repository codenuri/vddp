// Decorator - 65 page
#include <iostream>

// PhotoSticker : 스티커 사진기 라고 생각해 보세요

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};



class Emoticon 
{
	PhotoSticker* ps; 
public:
	Emoticon(PhotoSticker* ps) : ps(ps) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&\n"; 
		ps->draw(); 
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&\n"; 
	}
};

class Border 
{
	PhotoSticker* ps; 
public:
	Border(PhotoSticker* ps) : ps(ps) {}

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

	Border bo(&ps); 
	bo.draw();		
}
