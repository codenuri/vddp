#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// C 언어를 학습할때 : 메모리 구조를 이해하기 위해 "메모리 그림을 그려" 보면서 학습 합니다
// 디자인 패턴       : 클래스 구조를 이해하기 위해 "클래스 구조를 그려" 보면서 학습해야 합니다

// 55page 메뉴예제.. 그곳에 정리

// 모든 메뉴 클래스의 공통의 기반 클래스

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}
	std::string get_title() { return title;}


	// 모든 파생 클래스의 공통의 특징은 기반 클래스에도 있어야 한다.
	// => Rect, Circle 에 draw() 가 있다면 Shape 에도 draw() 가 있어야 한다.
	// => MenuItem, PopupMenu 에 command() 가 있다면 BaseMenu 에도 command() 가 있어야 한다.
	
	virtual void command() = 0; // 구현은 파생 클래스가 반드시 하도록!!
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";

		_getch(); 
	}
};

class PopupMenu : public BaseMenu
{
//	std::vector<MenuItem*> v; // MenuItem 만 보관 가능
	std::vector<BaseMenu*> v; // 모든 종류의 메뉴를 보관 가능
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m); }


	void command()
	{
		while( 1 )
		{
			system("cls");

			int sz = v.size();	

			for ( int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;

			if ( cmd < 1 || cmd > sz + 1)
				continue;

			if ( cmd == sz + 1 ) 
				break;			 
	
			v[cmd-1]->command();
		}
	}
};

int main()
{
	MenuItem m1("참치김밥",   11);
	MenuItem m2("소고기김밥", 12);

	MenuItem m3("라면", 51);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);

	PopupMenu pm("오늘의 점심 메뉴");
	pm.add(&kimbab); 
	pm.add(&m3);

	pm.command(); 
}




