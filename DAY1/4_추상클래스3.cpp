#include <iostream>


// 카메라를 그냥 만들지 말고
// 카메라와 카메라 사용자 사이에 지켜야 하는 규칙(인터페이스, 프로토콜)을 먼저 설계합니다

// 규칙 : "모든 카메라는 아래 클래스로 부터 상속 받아야 한다." 이렇게 표현하지 말고
//       "모든 카메라는 ICamera 인터페이스를 구현해야 한다" 라고 표현합니다.

// 인터페이스 만들때
// 1. class로 해도 되지만 struct 로 하는 경우도 많습니다(public 한줄을 사용하지 않아도 되므로)
// 2. 인터페이스도 결국 기반 클래스 이므로 "가상 소멸자" 잊지 마세요

//#define interface struct 
//class ICamera
struct ICamera
//interface ICamera
{
//public:
	virtual void take() = 0;

	virtual ~ICamera() {} // <== 가상 소멸자
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

// 이제 모든 카메라는 ICamera 에서 "상속 받아야 합니다." 라고 표현하지 말고
// 이제 모든 카메라는 ICamera 를   "구현해야 합니다."   라고 표현
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

// 추상 클래스 vs 인터페이스
// 인터페이스 : 지켜야 하는 규칙만 가진 경우            - 위 예제 ICamera
// 추상클래스 : 지켜야 하는 규칙 + 다른 멤버도 있는 경우 - 도형 편집기 예제 Shape
// => C++에서는 용어서 혼용되어서 사용되기도 합니다

// C#, Java : abstract, interface 라는 키워드 존재 - 명확히 구분됨
// C++      : 별도의 키워드 없음. 다른 멤버가 있냐에 따라 구분, 용어가 혼용되기도 함


// 강한 결합(tightly coupling)
// => 클래스가 다른 클래스 사용시 클래스 이름을 직접 사용하는것
// => People::use_camera(HDCamera*);
// => 교체 불가능한, 경직된 디자인

// 약한 결합(loosely coupling)
// => 클래스가 다른 클래스 사용시 클래스 이름을 직접 사용하지 않고
//    규칙을 담은 인터페이스 이름 사용
// => People::use_camera(ICamera*);
// => 교체 가능한, 유연한 디자인의 핵심. 

// C# 언어는 인터페이스를 아주 많이 사용합니다.