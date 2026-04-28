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

//	Frame f(&ps); // ps 객체에 액자 기능 추가

	Frame f( &e );  // ??? 기능을 추가한 객체에 다시 기능 추가				
					// 즉, 기능의 중첩
					// 현재 코드는 에러!!
					// => 다음 소스에서 해결.. 
	f.draw();	 


}

