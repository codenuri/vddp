#include <iostream>

// 각 OS 스타일의 컨트롤을 제공하기 위해

// 각 컨트롤의 공통의 인터페이스를 먼저 설계후
// => OS 별 컨트롤 제공

struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};

int main(int argc, char** argv)
{
	IButton* btn;

	if (strcmp(argv[1], "-style:OSX") == 0)
		btn = new OSXButton;
	else
		btn = new WinButton;

	// 그런데 !!
	// 프로그램에서 버튼같은 컨트롤을 한개만 만들까요 ??
	// 수십 ~ 수백개 컨트롤이 필요한데.. 그때 마다 위 코드 처럼  만들수 없습니다.

	// 해결책 : "공장" 을 통해서 컨트롤을 만들어야 합니다.
}



// QT : C++ 기반의 gui 라이브러리
// => 실행시 look and feel 을 변경하는 특징이 있음






