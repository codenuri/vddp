#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// Menu 6 : 안전성(Safety) 를 강조한 디자인
// Menu 7 : 편의성(comportable) 를 강조한 디자인


class UnsupportedOperation{};

class BaseMenu 
{
	std::string title;
public:
	BaseMenu( const std::string& title ) 
		: title(title) {}
	
	std::string get_title() const  { return title; }
	
	virtual ~BaseMenu() {}

	virtual void command() = 0;

	// 아래 멤버 함수는 Popup 에서만 필요하지만
	// 여기서 선언을 제공하면 사용자가 캐스팅 없이 사용가능합니다
	virtual BaseMenu* get_submenu(int idx) { throw UnsupportedOperation();}
	virtual void add(BaseMenu*) { throw UnsupportedOperation(); }
};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) 
		: BaseMenu(title), id(id) {}


	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨\n";
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m);}

	void command()
	{
		while(1)
		{
			system("cls");

			auto sz = v.size();

			for ( int i = 0; i < sz; i++)
			{
				std::cout << i +1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if ( cmd == sz + 1) 
				break;			

			if ( cmd < 1 || cmd > sz + 1 )  
				continue;

			v[cmd-1]->command();

		}



	}

	BaseMenu* get_submenu(int idx) { return v[idx];}
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");

	root->add(pm1);
	root->add( new MenuItem("UHD",  23));


//	static_cast<PopupMenu*>(root->get_submenu(0))->add( new MenuItem("RED", 11));

	root->get_submenu(0)->add( new MenuItem("RED", 11));

	root->command();
}


