#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem 
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() { return title;}

	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";

		_getch(); 
	}
};

class PopupMenu 
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

	// 핵심 : PopupMenu 를 선택할때 호출되는 함수
	void command()
	{
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 51);

	PopupMenu pm("오늘의 점심 메뉴");
	pm.add(&m1);
	pm.add(&m2);

	pm.command(); // 팝업 메뉴 선택시 해야할 일을 생각해 보세요
}




