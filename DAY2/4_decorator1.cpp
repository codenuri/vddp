#include <iostream>

// PhotoSticker : 스티커 사진기 라고 생각해 보세요

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 상속을 사용한 기능의 추가
class Emoticon : public PhotoSticker
{
public:
	void draw()	
	{ 
		std::cout << "&&&&&&&&&&&&&&&&&&&&\n";  // 이모티콘 그림 - 즉, 기능의 추가
		PhotoSticker::draw();					// 기존 기능 사용		
		std::cout << "&&&&&&&&&&&&&&&&&&&&\n";  // 이모티콘 그림
	}

};


int main()
{
	PhotoSticker ps;
	ps.take();	// 사진 촬영
	ps.draw();	// 사진 출력(인화)
}