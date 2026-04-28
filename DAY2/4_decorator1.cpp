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
// 사진에 액자 그림을 추가하는 클래스
class Frame : public PhotoSticker
{
public:
	void draw()	
	{ 
		std::cout << "====================\n";  
		PhotoSticker::draw();					
		std::cout << "====================\n";  
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	// 사진 촬영
	ps.draw();	// 사진 출력(인화)

	Emoticon e;
	e.take();
	e.draw(); // 사진 출력 + 이모티콘 출력

	Frame f;
	f.take();
	f.draw();	
}

// 위 코드는 상속을 사용해서 기능을 추가한 코드 입니다.
// => 아래 중에서 어떤 것일까요 ?
// 1. 객체에 기능 추가 ?
// 2. 클래스에 기능 추가 ?