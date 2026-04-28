#include <iostream>

// PhotoSticker : 스티커 사진기 라고 생각해 보세요

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 상속을 사용한 기능의 추가 : 클래스에 기능 추가
// 포함을 사용한 기능의 추가 : 객체에 기능 추가
class Emoticon 
{
	PhotoSticker* origin; // [핵심] 값이 아닌 포인터 또는 참조
						 // 의도 : 이미 생성되어 있는 객체를 가리키겠다는 것
public:

	Emoticon(PhotoSticker* ps) : origin(ps){}
	
	void draw()	
	{ 
		std::cout << "&&&&&&&&&&&&&&&&&&&&\n";  // 기능 추가
		origin->draw();					
		std::cout << "&&&&&&&&&&&&&&&&&&&&\n";  
	}
};

int main()
{
	PhotoSticker ps;	
	ps.take();	
	ps.draw();	

	Emoticon e(&ps); // e 는 이미 존재 하는 ps 에 기능을 추가하는 기능 추가 객체!!
					 // 사진 자체는 이미 ps 객체가 촬영했고
					 // e 가 하는 일은 ps 에 기능을 추가하는 것
	e.draw();
}

