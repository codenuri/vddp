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

	// 이미 촬영된 사진( ps 객체 ) 에 이모티콘을 추가한것이 아니라
	// 이모티콘을 추가하기 위해 사진을 새로 촬영한것
	// 즉, 이미 존재하는 객체(ps)에 기능 추가가 아니라
	// 기능이 추가된 새로운 객체를 만든 것 
	Emoticon em;
	em.take();	
	em.draw();	
}
