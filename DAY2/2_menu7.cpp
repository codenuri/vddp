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
	// 하위 메뉴를 얻는 멤버 함수
	BaseMenu* submenu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상변경");
	PopupMenu* pm2 = new PopupMenu("해상도변경");

	root->add(pm1);
	root->add(pm2);
	root->add( new MenuItem("POWEROFF", 31));

	pm1->add( new MenuItem("RED",   11));
	pm1->add( new MenuItem("GREEN", 12));
	pm2->add( new MenuItem("HD",   21));
	pm2->add( new MenuItem("FHD",  22));


	// 이번 단계의 핵심
	auto m = root->submenu(0);
//	m->add( new MenuItem("BLACK", 13)); // 의도 : 색상 팝업 메뉴에 새로운 메뉴 추가
										// 하지만 error.
										// 현재 m 은 "PopupMenu" 객체가 맞지만 
										// m 의 타입은 BaseMenu* 인데, BaseMenu 에는 add 가 없다

	// 해결책 #1. 캐스팅
	static_cast<PopupMenu*>(m)->add( new MenuItem("BLACK", 13));


	root->command();
}
