#include <iostream>
#include <string>
#include <conio.h>
// GUI 프로그램에서 사용하는 Widget(Control) 를 생각해 봅시다.

class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		std::cin >> data;
		return data;
	}
};

int main()
{
	Edit e;		// 입력창(Edit) 생성
				// => 입력된 데이타를 꺼내려면 get_data() 호출

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


