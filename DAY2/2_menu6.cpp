#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}
	std::string get_title() { return title;}

	virtual void command() = 0; 
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
	std::vector<BaseMenu*> v;
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
	// 아래 코드를 보고 메뉴의 구조를 생각해 보세요
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상변경");
	PopupMenu* pm2 = new PopupMenu("해상도변경");

	root->add(pm1);
	root->add(pm2);
//	pm1->add(pm2);

	pm1->add( new MenuItem("RED",   11));
	pm1->add( new MenuItem("GREEN", 12));
	pm1->add( new MenuItem("BLUE",  13));
	pm1->add( new MenuItem("WHITE", 14));

	pm2->add( new MenuItem("HD",   21));
	pm2->add( new MenuItem("FHD",  22));
	pm2->add( new MenuItem("UHD",  23));

	// 이제 메뉴를 시작하려면 ??
	root->command();
}

// 객체지향 프로그래밍 관점에서 바라본 "프로그램 이란?"

// 1. 객체를 생성하고
// 2. 객체간의 관계를 설정하고
// 3. 객체간에 메세지를 주고 받는 과정(서로의 멤버 함수를 호출한다는 것)

// 4. 프로그램의 기본 단위는 "함수" 가 아닌 "클래스" 이다.

// 장점 : 유지보수가 쉽고 확장성이 좋다.

// 단점 : 메모리 사용량이 커질수 있고(사용되지 않은 멤버 데이타등이 있을수 있다)
//       성능이 약간 저하(가상함수등)
//       결정적으로 "어렵다!!" - 객체지향 디자인을 이해하는 것은 많은 학습이 필요

