#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 - template method
// 2. 변하는 것을 다른 클래스로 - strategy!!

// Validation 정책을 담은 별도의 클래스를 설계한다.
// => 교체 가능해야 하므로
// => 인터페이스를 먼저 설계 한다.

struct IValidator 
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual ~IValidator() {}
};

// 이제 다양한 정책을 가진 Validator 를 만드세요
// => 이메일형식확인, 주민번호, 사번 규칙등... 

class DigitValidator : public IValidator 
{
	int limit;
public:
	DigitValidator(int n) : limit(n) {}

	bool validate(const std::string& s, char c) override 
	{
		return s.size() < limit && isdigit(c);
	}
};


class Edit
{
	std::string data;

	IValidator* val = nullptr;
public:
	void set_validator(IValidator* p) { val = p;}

	std::string get_data()
	{
		data.clear();
		while( 1 )
		{
			char c = _getch();
			
			if ( c == 13 ) break; 

			if ( val == nullptr || val->validate(data, c) ) // 값의 유효성 확인을
			{								// 다른 객체에 위임
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;

	}
};
int main()
{
	Edit e;

	DigitValidator v(5); // 5자리 이하 숫자만 허용하는 Validator
	
	e.set_validator(&v); // edit 가 사용할 Validator 전달

	DigitValidator v2(15); 
	
	e.set_validator(&v2); // 실행시간 Validation 정책 변경 가능
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


