#include <iostream>


// 구체적인 카메라를 먼저 만들지 말고
// 카메라 제작자와 사용자 사이에 지켜야 하는 "규칙" 을 먼저 설계 합니다.

// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다." 라고 표현하지말고
// 	      "모든 카메라는 아래 인터페이스를 구현 해야 한다." 라고 표현

//#define interface struct 

// class ICamera  // 접근 지정자 생략시 디폴트는 private
struct ICamera    // 접근 지정자 생략시 디폴트는 public
//interface ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {} // 인터페이스도 결국 기반 클래스 입니다
						  // 소멸자를 가상함수로 해야 합니다.
};



// 실제 카메라가 없어도 "사용하는 코드 작성 가능" 합니다.
// => 규칙 대로만 사용하면 됩니다
class People 
{
public:
	void use_camera(ICamera* c) { c->take();}
};

// 이제 모든 카메라는 "규칙"을 지켜야 합니다.
class Camera : public ICamera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:	
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:	
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

	UHDCamera uhc;
	p.use_camera(&uhc); // 기존 People 클래스 수정없이
						// 새로운 카메라 사용가능
						// "OCP" 만족
}

// 강한 결합(tightly coupling)
// => 클래스가 다른 클래스 사용시, 이름을 직접 사용하는것
// => People::use_camera(HDCamera*) 
// => 교체 불가능한 경직된 디자인


// 약한 결합(loosely coupling)
// => 클래스가 다른 클래스 사용시, 규칙을 담은 추상클래스(인터페이스) 사용하는것
// => People::use_camera(ICamera*) 
// => 교체 가능한 유연한 디자인

// 인터페이스 : 규칙(순수가상함수)만 담고 있는것
// 추상클래스 : 규칙 + 다른 멤버도 같이 제공하는 경우

// C#, Java : interface, abstract 라는 별도의 키워드 제공
// C++      : 별도 키워드 없음. 모두 추상클래스 문법으로 구현
