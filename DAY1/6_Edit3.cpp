#include <iostream>
#include <string>
#include <conio.h>

// 핵심 : validation 정책은 변경 가능해야 한다.
// => Edit 같은 클래스는 라이브러리 내부 클래스
// => 즉, Edit 를 직접 수정하도록 할수는 없다.
// => 다른 방법을 제공해야 한다.

// 공통성과 가변성의 분리 
// 방법 #1. 변하는 것을 가상함수로

class Edit
{
	std::string data;
public:

	// validation 정책을 별도의 가상함수로 분리
	virtual bool validate(char c)
	{
		return true;
	}

	std::string get_data()
	{
		data.clear();

		while(1)
		{
			char c = _getch(); 

			if ( c == 13 )
				break;

			if ( validate(c) ) // validation 정책의 확인은 가상함수 호출해서 결정
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl;
		return data;
	}
};

int main()
{
	Edit e;	

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


