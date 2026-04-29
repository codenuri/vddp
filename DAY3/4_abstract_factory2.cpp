
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
//----------------
// 

// GOF's 의 디자인 패턴에는 "Factory" 라는 패턴은 없습니다.

// => "abstract factory" 라는 이름이 있습니다.
// => "factory" 도 인터페이스를 먼저 만들어서 교체 가능하게 하자는 의도

// => 그런데, 실전에서는 "인터페이스 없는 factory" 도 널리 사용됩니다.

// => "GOF's 의 디자인 패턴" 는 참고 일뿐, 반드시 동일하게 만들 필요 없습니다.
//    프로젝트에 맞게 수정해서 구현하면 됩니다.

struct IFactory 
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit()   = 0;
	virtual ~IFactory() {}

	// 실제로 컨트롤은 수십 ~ 수백개가 있으므로 
	// 각 콘트롤을 만드는 수십개의 함수 제공
};


//  style 에 따른 컨트롤을 생성하는 공장
class WinFactory 
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit*   CreateEdit()   { return new WinEdit; }
	virtual ~WinFactory() {}
};
class OSXFactory 
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

	IEdit* edit = factory->CreateEdit();
	edit->Draw();	
}











