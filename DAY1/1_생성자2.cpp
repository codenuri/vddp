#include <iostream>

class Base
{
public:
	Base(int a){ }
	~Base()    { }
};
// 아래 코드에서 에러를 모두 찾으세요 
// 핵심 : 기반 클래스인 Base 에 디폴트 생성자가 없다는 점. 
class Derived : public Base
{
public:					
	// 사용자 코드			// 컴파일러 변경 코드
//	Derived()		{ }		// Derived()      : Base() { }
//	Derived(int a)	{ }		// Derived(int a) : Base() { }

	// 해결책
	// 기반 클래스에 디폴트 생성자가 없다면
	// 반드시 파생 클래스에서 기반 클래스의 다른 생성자를 명시적으로 호출해야 합니다.
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}

	~Derived()		{ }
};
int main()
{

}
