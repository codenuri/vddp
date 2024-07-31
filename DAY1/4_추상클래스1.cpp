// 1_추상클래스1.cpp - 10page

// 추상 클래스 : 순수 가상함수가 한개 이상 있는 클래스
// 특징 : 객체를 생성할 수 없다.
// 의도 : 약속된 함수를 반드시 만들라고 "지시" 하기 위한 문법
class Shape
{
public:
	virtual void draw() = 0; // 순수 가상함수(pure virtual function)
							 // => 구현부가 없고, "= 0" 으로 표기
};

class Rect : public Shape
{
	// draw 의 구현부를 제공하지 않으면 Rect 도 추상
	// draw 의 구현부를 제공하면 추상이 아닌 구체(Concrete)
public:
	void draw() override {}
};
int main()
{
	Shape  s; // error
	Shape* p; // ok
	Rect  r;  // ok
}
