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
	p.use_camera(&hc);	// ok  
}
// 위 코드는  아무 문제 없이 컴파일 되지만
// OCP 위반 입니다.
// 나중에 등장한 HDCamera 때문에 기존에 있던 People 코드가 수정..





