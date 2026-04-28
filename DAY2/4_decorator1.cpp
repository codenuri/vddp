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
	PhotoSticker ps;			// PhotoSticker : 클래스(타입)
								// ps : 객체 
	ps.take();	// 사진 촬영
	ps.draw();	// 사진 출력(인화)

	// 이미 위 코드에서 사진은 촬영 되었고, ps 객체가 보관 합니다.
	// 아래 코드는 이미 존재 하는 ps 객체에 기능 추가가 아니라.
	// 기능 추가를 하기 위해 새로운 객체를 만든것!!

	Emoticon e;
	e.take();
	e.draw(); // 사진 출력 + 이모티콘 출력

	Frame f;
	f.take();
	f.draw();	
}

// 위 코드는 상속을 사용해서 기능을 추가한 코드 입니다.
// => 아래 중에서 어떤 것일까요 ?
// 1. 객체에 기능 추가 ?  => 현재 코드!!!
// 2. 클래스에 기능 추가 ?

// 위 코드의 또 다른 단점
// => Emoticon 과 Frame 기능을 동시에 추가하려면
// => 다시 다중 상속의 모양으로 해야 합니다.
// => 복잡해집니다.!!!!
// => 다음 단계에서 다른 방식으로 만들어 봅시다.
