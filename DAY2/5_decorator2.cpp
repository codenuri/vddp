// Decorator - 65 page
#include <iostream>

// PhotoSticker : 스티커 사진기 라고 생각해 보세요

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 상속 : 객체가 아닌 클래스에 기능을 추가하는 것

// 포함을 사용하면 클래스가 아닌 객체에 기능 추가를 할수 있다.


class Emoticon 
{
	PhotoSticker* ps; // 핵심 : 포인터 또는 참조 멤버로 포함!!!
					  // 외부에 이미 생성되어 있는 객체를 가리키겠다는것
public:
	Emoticon(PhotoSticker* ps) : ps(ps) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&\n"; // 추가된기능
		ps->draw(); // 기존에 있던 기능
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&\n"; 
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	

	ps.draw();	// ps 객체의 기능을 직접 사용

	Emoticon em(&ps); // em 은 ps 에 기능을 추가하는 객체
	
	em.draw();	// 1. em 이 추가한 기능 사용
				// 2. ps 가 가진 기능도 사용
}
