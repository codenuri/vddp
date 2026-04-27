// 1_추상클래스1.cpp - 10page

// 추상 클래스(abstract class )
// 정의 : 순수 가상함수가 1개 이상 있는 클래스
// 특징 : 객체를 생성할수 없다. 
// 의도 : 특정 멤버 함수는 반드시 만들어야 한다고 약속하는 것


//abstract class Shape // java, C#
class Shape			   // C++
{
public:
	virtual void draw() = 0; // 순수 가상 함수(pure virtual function)
	 						 // => 함수 구현이 없고, "=0" 으로 표기
};
class Rect : public Shape
{
	// draw() 의 구현을 제공하지 않으면 Rect 도 추상
	// draw() 의 구현을 제공하면       Rect 는 추상 아님. 구체(concrete) 라고 표현
public:
	void draw() override {} 
};

int main()
{
	Shape  s; // error.
	Shape* p; // ok 
	Rect  r;  // ok 
}
