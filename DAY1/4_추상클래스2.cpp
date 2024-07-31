//1_추상클래스2.cpp
#include <iostream>


class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:	
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void use_camera(Camera* p)   { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ??? 
}

// OCP
// 기능 확장에는 열려있고(Open, 새로운 모듈/클래스가 추가되어도)
// 코드 수정에는 닫혀있어야(Close, 기존 코드는 수정되지 않도록 )
// 해야 한다는 원칙(Principle)

// Open Close Principle  (개방폐쇄의 법칙)

// 객체지향 설계의 5대 원칙
// => SOLID : SRP, OCP, LSP, ISP, DIP





