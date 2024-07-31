#include "monitor.h" 

// 어떤 일을 해야 할때
// C 언어 : 그일을 직접 하거나, 그일을 하는 함수를 만들게 됩니다.
//        => "해당 작업만" 할수 있습니다

// Command 패턴 : 해당 작업을 하는 "클래스" 를 설계 하라는 것
//		  => "주어진 작업을 수행" 하고
//		  => "취소 하는 방법도 추가" 할수 있다.
//        => "취소 할때 필요한 데이타" 도 보관가능
//        => 명령을 자료구조에 보관도 가능(stack 등..)

// 모든 명령의 인터페이스
struct ICommand 
{
	virtual void execute() = 0;
	virtual void undo() {} // undo 할수 없는 명령도 있다.
	virtual ~ICommand() {}
};


class BrightnessCommand : public ICommand
{
	Monitor& m;
	int value;
	int old_value = 0;
public:
	BrightnessCommand(Monitor& m, int value) : m(m), value(value) {}

	void execute() 
	{
		old_value = m.get_brightness();
		m.set_brightness(value);
	}
	void undo()
	{
		m.set_brightness(old_value);
	}
};

int main()
{
	Monitor m;

	

	// #1. m 객체의 멤버 함수를 직접 호출

	int old_value = m.get_brightness();
	m.set_brightness(90);

	// 모니터 밝기를 이전상태로 해보세요
	m.set_brightness(old_value);


	// #2. Command 패턴 사용

	BrightnessCommand cmd(m, 90);
	cmd.execute();
	cmd.undo();


}
