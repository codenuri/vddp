#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그래밍
// => 프로그램의 모든 요소를 객체로 생각하는 것
// => 프로그램에서 필요한 타입을 먼저 설계해야 한다.

class MenuItem 
{
	// 메뉴 아이템이 가져야 하는 속성을 멤버 데이타로 표현 합니다
	std::string title;
//	std::string hotkey;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() { return title;}

	// 메뉴가 선택 되었을때 호출되는 함수	
	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";

		_getch(); // 아무 키나 누를때 까지 대기
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 51);

	m1.command(); // 메뉴를 선택하면 "command" 가 호출된다고 가정.
}




