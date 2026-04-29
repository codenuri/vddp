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

// 어떤 일을 해야 할때
// C 언어 :  그일을 직접 하거나, 그일을 하는 함수를 만들게 됩니다
//			=> "해당 작업만" 할수 있습니다.
//			=> 그런데, 어떤 작업은 "취소" 라는 개념도 있고, 
//			   취소하기 위한 데이타(이전 상태값)도 필요합니다.
//			   결국 C 스타일로 하면, 취소하기 위한 모든 데이타를 외부에서 보관해야 합니다. 

// Command 패턴 : 해당 작업을 하는 "클래스" 를 설계 하라는 것
//			=> "해당 작업을 실행" 할수도 있고, => Execute() 멤버함수
//          => "해당 작업을 취소" 할수도 있고, => Undo() 멤버함수
//          => "취소에 필요한 데이타" 도 보관가능. 


