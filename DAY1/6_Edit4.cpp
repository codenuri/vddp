#include <iostream>
#include <string>
#include <conio.h>

// 핵심 : 변하는 것을 분리하는 2가지 방법

// #1. 변하는 것을 가상함수로 분리
// => edit3.cpp 의 validate 가상함수
// => template method 패턴

// #2. 변하는 것을 다른 클래스로 분리
// => 현재 예제

// Validation 정책이 지켜야 하는 규칙을 담은 인터페이스
struct IValidator 
{
	virtual bool validate(const std::string& s, char) = 0;
	virtual bool is_complete(const std::string& s) { return true;}

	virtual ~IValidator() {}
};

// 주민 등록 번호 : 901  1     확인




class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		data.clear();

		while(1)
		{
			char c = _getch();

			if ( c == 13 ) 
				break;

			if ( isdigit(c) )
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


