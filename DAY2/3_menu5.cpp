#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// C 언어 : 메모리 그림을 그려서 메모리 구조를 이해 합니다.

// 객체지향 디자인 : 클래스 Diagram(관계도) 를 그려서 디자인 패턴을
//				   이해하면 편리합니다.


class BaseMenu 
{
	std::string title;
public:
	BaseMenu( const std::string& title ) 
		: title(title) {}
	
	std::string get_title() const  { return title; }
	
	virtual ~BaseMenu() {}

	// 모든 메뉴는 선택될수 있다
	// 구현은 파생클래스에서 제공!!
	virtual void command() = 0;
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
};




int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2);

	pm1->add( new MenuItem("RED",   11));
	pm1->add( new MenuItem("GREEN", 12));
	pm1->add( new MenuItem("BLUE",  13));

	pm2->add( new MenuItem("HD",   21));
	pm2->add( new MenuItem("FHD",  22));
	pm2->add( new MenuItem("UHD",  23));

	// 이제 시작하려면 ???

}





