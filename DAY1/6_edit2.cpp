#include <iostream>
#include <string>
#include <conio.h>

// 핵심 : Validation 정책은 사용자가 변경할수 있어야 합니다.

class Edit
{
	std::string data;
public:

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 안에 있는 변해야 하는 코드는 분리되어야 합니다.
	// => 변하는 부분을 별도의 가상함수로 분리

	virtual bool validate( char c)
	{
		return true;
	}


	std::string get_data()
	{
		data.clear();

		while( 1 )
		{
			char c = _getch();
			
			if ( c == 13 ) break; // enter 입력

			if ( validate(c) ) // validation 방법을 가상함수에 의존
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 위 코드의 의도
// => Validation 정책을 변경하려면
// => 파생 클래스를 만들어서 약속된 가상함수를 override 하라는 것
class NumEdit : public Edit 
{
public:
	bool validate(char c) override 
	{
		return isdigit(c);
	}
};
int main()
{
//	Edit e;
	NumEdit e;
//	AddressEdit e2;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


