#include <iostream>
#include <string>
#include <conio.h>

// 핵심 : 값의 유효성을 확인하는 "Validation" 기능 추가

class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		data.clear();

		while(1)
		{
			char c = _getch(); // 한자만 키보드에서 직접 입력

			if ( c == 13 ) // enter
				break;

			if ( isdigit(c) )
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cin >> std::endl;
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


