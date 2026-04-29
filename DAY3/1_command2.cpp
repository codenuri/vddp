#include "monitor.h"

class BrightnessCommand
{
	Monitor& m;	
	int value;
	int old_value;
public:
	BrightnessCommand(Monitor& m, int v) : m(m), value(v) {}

	void Execute()
	{
		old_value = m.get_brightness();
		m.set_brightness(value);
	}
	void Undo() 
	{
		m.set_brightness(old_value);
	}
};

int main()
{
	Monitor m;
	
	int old_value = m.get_brightness();
	m.set_brightness(90);

	// 이전에 한 작업(밝기 변경)을 취소(또는 이전 상태 복구)하고 싶다. 
	// => 결국 아래 코드는 모니터 객체의 상태를 외부에서 꺼내서 보관하고 있다가 사용해야 합니다
	// => 모니터의 상태가 복잡하면 외부에서 많은 데이타를 보관하고 있어야 합니다
	m.set_brightness(old_value);


	// 그런데, command 패턴으로 하면	
	BrightnessCommand cmd(m, 90);
	cmd.Execute(); 	
	cmd.Undo();     // 함수 호출 한번으로 해결
				    // 이전 상태는 cmd 객체 내부에 보관
}