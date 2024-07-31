// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// #1. 가상함수 오버라이드시에 "virtual" 없어도 됩니다.
//	virtual void foo() {} // 이 코드와
//	void foo() {} 		  // 이 코드는 동일. virtual 없지만 virtual 입니다.


	// #2. 가상함수 오버라이드시에 실수(오타)가 있어도
	// => 에러 아닙니다. 새로운 함수를 만들었다고 컴파일러는 생각
	// => 이 문제가 수없이 많은 버그의 원인이 되었습니다.
//	virtual void fooo() {}
//	virtual void goo(double){}

	// #3. 위 2번 문제를 해결하기 위해 c++11 에서 override 키워드 도입
	virtual void fooo() override {}
	virtual void goo(double) override {}
};

int main()
{
}





