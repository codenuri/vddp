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
	MenuItem m1("참치  김밥", 11);
	MenuItem m2("소고기 김밥", 12);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);

	MenuItem m5("라면", 51);

	PopupMenu pm("오늘의 점심");

	pm.add(&kimbab);   
	pm.add(&m5);

	pm.command(); 	

}





