#include "monitor.h" // 이파일 추가하고, git 에서 소스 복사해 오세요

class BrightnessCommand 
{
	Monitor& m;
	int value;
public:
	BrightnessCommand(Monitor& m, int value) : m(m), value(value) {}

	void execute() { m.set_brightness(value);}
};

int main()
{
	Monitor m;

	// 모니터의 밝기를 변경하고 싶다.

	// #1. m 객체의 멤버 함수를 직접 호출
	m.set_brightness(90);


	// #2. Command 패턴 사용
	// => 모니터의 밝기를 변경하는 명령객체를 만들어서 실행
	BrightnessCommand cmd(m, 90);
	cmd.execute();
}
