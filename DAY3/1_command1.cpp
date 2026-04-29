#include "monitor.h"


// 모니터의 밝기를 변경할때 사용하는 클래스
class BrightnessCommand
{
	Monitor& m;	
	int value;
public:
	BrightnessCommand(Monitor& m, int v) : m(m), value(v) {}

	void Execute()
	{
		m.set_brightness(value);
	}
};

int main()
{
	Monitor m;
	
	// 모니터의 밝기를 변경하고 싶다.
	// #1. m 객체의 멤버함수를 직접 호출
	m.set_brightness(90);


	// #2. command 패턴을 사용하는 방법
	BrightnessCommand cmd(m, 90);
	cmd.Execute(); 	// 이순간 m.set_brightness(90) 실행
}