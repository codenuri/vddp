#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
class unsupported_operation{};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}
	std::string get_title() { return title;}

	virtual void command() = 0; 

	virtual void add(BaseMenu* m)      { throw unsupported_operation(); }
	virtual BaseMenu* submenu(int idx) { throw unsupported_operation(); }
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

	~PopupMenu()
	{
		for( auto m : v)
			delete m;
	}


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

	root->command();

	// 위 모든 메뉴 객체는 new 를 사용해서 만들었습니다.
	// 종료전에 반드시 delete 해야 합니다.
	// 방법 #1. raw pointer 대신 스마트 포인터 사용(std::shared_ptr)
	// 방법 #2. root 만 delete 하고 PopupMenu 소멸자가 자신의 하위 메뉴를 delete
	delete root;
}

// 메뉴 예제를 통해서 꼭 알아두어야 할것

// 1. 필요한 타입을 먼저 설계 한다.
// => 파워 포인트 프로그램 이라면 "Rect", "Circle" 클래스를 먼저 설계
// => 메뉴가 필요 하면 "MenuItem", "PopupMenu" 같은 클래스를 먼저 설계
//    메뉴 자체를 하나의 타입으로 생각하는 관점

// 2. 그리고, 적절한 디자인 패턴을 적용
// => 모든 도형을 그릴때 공통의 작업이 있고, 각 도형별 다른 작업이 있다
//    "template method" 적용
// => PopupMenu 는 MenuItem 과 PopupMenu 모두를 보관 할수 있다
//    "공통의 기반 클래스를 설계"
//    "composite pattern"