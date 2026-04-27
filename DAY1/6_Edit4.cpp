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
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true;}

	virtual ~IValidator() {}
};
// 주민 등록 번호 : 901  1     확인


class Edit
{
	std::string data;

	//----------------------------------------
	IValidator* val = nullptr;
public:
	void set_validator(IValidator* v) { val = v; }
	//----------------------------------------

	std::string get_data()
	{
		data.clear();

		while(1)
		{
			char c = _getch();

			if ( c == 13 && (  val == nullptr || val->is_complete(data) )  ) 
				break;

			if ( val == nullptr || val->validate(data, c) ) // 입력 값의 유효성을 validation 객체를 통해서 확인
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl;
		return data;
	}
};
// 이제 Edit 같은 입력도구에서 사용될 다양한 validator 를 제공하면 됩니다.
class LimitDigitValidator : public IValidator 
{
	int value = 0;
public:
	LimitDigitValidator(int v) : value(v) {}

	bool validate(const std::string& s, char c) override 
	{
		return s.size() < value && isdigit(c);
	}
	bool is_complete(const std::string& s) override 
	{
		return s.size() == value;
	}
};
int main()
{
	Edit e;	

	// Edit 객체 e 에 유효성 확인 객체 연결
	LimitDigitValidator v(5); // 5자리까지의 숫자만 입력 가능
	e.set_validator(&v);

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


