// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// DLL 안에 있는 Proxy 클래스 이름은 
// => Client 제작자가 알수도 없고, 사용해도 안됩니다(강한결합)
// => DLL 내부에서 new Calc 해야 합니다
extern "C" __declspec(dllexport)
ICalc* create()
{
	return new Calc();
}

// 새로운 Proxy DLL 을 만들어도 
// => DLL 이름은 동일하게 유지하고
// => DLL 내부에서 create() 함수 이름도 동일하게 유지. 