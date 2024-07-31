// Decorator - 65 page
#include <iostream>

// PhotoSticker : 스티커 사진기 라고 생각해 보세요

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 스티커 사진에 다양한 이모티콘등을 추가할수 있게 해 봅시다.
// => 기능의 추가

// 방법 #1. 상속을 사용한 기능의 추가
class Emoticon : public PhotoSticker
{
public:
	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&\n"; // 추가된기능
		PhotoSticker::draw(); // 기존에 있던 기능
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&\n"; 
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	// 사진 촬영
	ps.draw();	// 사진 출력(인화)

	Emoticon em;
	em.take();	
	em.draw();	

}
