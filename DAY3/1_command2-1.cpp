#include "monitor.h"

// 일반적인 코딩 관례
// 모든 명령의 공통의 인터페이스를 먼저 설계
struct ICommand
{
	virtual void Execute() = 0;
	virtual void Undo() {}
	virtual ~ICommand() {}
};

class BrightnessCommand : public ICommand 
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
	
	BrightnessCommand cmd(m, 90);
	cmd.Execute(); 	
	cmd.Undo();     
}

