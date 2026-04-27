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
	// #1. 가상함수 재정의시
	// => virtual 을 붙여도 되고 생략해도 됩니다.
	// => 아래 2줄은 동일한 의미
//	virtual void foo() {}
//	void foo() {}

	// #2. 가상함수 재정의시 실수(오타)가 있어도
	// => 컴파일 에러가 아닙니다.
	// => 컴파일러는 다른 이름의 함수를 새롭게 만들었다고 생각
//	virtual void fooo() {}
//	virtual void goo(double){}

	// #3. #2 때문에 나타나는 버그를 없애기 위해서
	// => C++11 부터 override 키워드 추가
	// => 새로운 함수가 아니라 기반 클래스 가상함수를 다시 만드는 것이라고 컴파일러에게 알려주는 것
	virtual void fooo() override {}
	virtual void goo(double) override {}	

	// 결론 :가상 함수 재정의시에는 반드시 override 붙이세요
	// 붙이지 않아도 에러는 아니지만, 붙이는 것이 안전한 코드. 
};

int main()
{
}





