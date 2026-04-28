#include <iostream>

// PhotoSticker : 스티커 사진기 라고 생각해 보세요

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};
//----------------------------------------
class Emoticon 
{
	PhotoSticker* origin; 
public:

	Emoticon(PhotoSticker* ps) : origin(ps){}
	
	void draw()	
	{ 
		std::cout << "&&&&&&&&&&&&&&&&&&&&\n";  
		origin->draw();					
		std::cout << "&&&&&&&&&&&&&&&&&&&&\n";  
	}
};
class Frame 
{
	PhotoSticker* origin; 
public:
	Frame(PhotoSticker* ps) : origin(ps){}
	
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

	Emoticon e(&ps);
	e.draw();	

	Frame f( &e );
	f.draw();	 


}

