
#include <iostream>

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
//-----------------

// 추상 팩토리 패턴 : 공장도 인터페이스를 먼저 설계해서 교체 가능하게 한다

struct IFactory 
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
	virtual ~IFactory() {}
};

//  style 에 따른 컨트롤을 생성하는 공장
class WinFactory : public IFactory
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit*   CreateEdit()   { return new WinEdit; }
	virtual ~WinFactory() {}
};
class OSXFactory : public IFactory
{
public:
	IButton* CreateButton() { return new OSXButton; }
	IEdit*   CreateEdit() { return new OSXEdit; }
	virtual ~OSXFactory() {}
};

int main(int argc, char** argv)
{
	IFactory* factory;

	if (strcmp(argv[1], "-style:OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;

	// 이제 공장을 사용해서 컨트롤을 생성합니다.
	IButton* btn = factory->CreateButton();
	btn->Draw();
}











