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

	// 아래 함수는 PopupMenu 와 MenuItem 에 공통으로 필요
	virtual void command() = 0; 

	// 아래 함수들은 PopupMenu 만 사용하는 함수
	// => 기본 구현은 예외 발생
	// => PopupMenu 에서만 재정의
	// => PopupMenu 객체에 대해서 호출시 정상 동작
	// => MenuItem  객체에 대해서 호출시 예외 발생
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

	// 캐스팅 없이 아래 처럼 그냥 사용하려면 어떻게 해야 할까 ?
	// 해결책은 "BaseMenu" 에도 add 필요
	m->add( new MenuItem("BLACK", 13)); 

 	root->submenu(0)->add( new MenuItem("WHITE", 14)); 

	// [참고] 아래 처럼 사용하면 예외 발생

 	root->submenu(2)->add( new MenuItem("WHITE", 14)); 
	//		      ^ PopupMenu 가 아닌 MenuItem(PowerOff)

	root->command();
}

// 가상함수가 오버헤드가 있지만
// => 프로그램에서 가끔 호출된다면 무시하세요
// => 루프 안에서 수만 ~ 수백만 번 호출되는 경우만 주의 하세요..

// menu7.cpp : 캐스팅 필요
// menu8.cpp : 캐스팅 필요 없음
// static_cast<PopupMenu*>(root->submenu(0))->add( new MenuItem("WHITE", 14)); 
//                         root->submenu(0) ->add( new MenuItem("WHITE", 14)); 