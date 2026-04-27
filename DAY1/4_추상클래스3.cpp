#include <iostream>


// 카메라를 그냥 만들지 말고
// 카메라와 카메라 사용자 사이에 지켜야 하는 규칙(인터페이스, 프로토콜)을 먼저 설계합니다

// 규칙 : 모든 카메라는 아래 클래스로 부터 상속 받아야 한다.

class ICamera
{
public:
	virtual void take() = 0;
};

// 아직 진짜 카메라가 없지만, 규칙은 있습니다.
// 카메라를 사용하는 코드를 먼저 만들어도 됩니다.
// 규칙대로만 사용하면 됩니다.

class People
{
public:	
	// [핵심] 인자가 특정 제품의 이름이 아닌 규칙(인터페이스) 이름
	void use_camera(ICamera* p) { p->take(); }
};

// 이제 모든 카메라는 ICamera 에서 상속 받아야 합니다.
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
	p.use_camera(&uhc);	// People 클래스의 수정 없이 
						// 새로운 카메라 사용가능.
						// OCP 를 만족하는 좋은 코드
}



