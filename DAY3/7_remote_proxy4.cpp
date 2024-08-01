#define USING_GUI
#include "cppmaster.h"

// Client 개발자는 Server 개발자에게 2개이 파일을 받아야 합니다.
// ICalc.h       : 인터페이스가 있는 헤더
// CalcProxy.dll : Proxy 클래스가 있는 동적 모듈(리눅스 .so)

#include "ICalc.h"

/*
ICalc* load_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
						// windows : LoadLibrary()
						// linux   : dlopen()

	using F = ICalc*(*)();

	F f = (F)ec_get_function_address(addr, "create");
						// windows : GetProcAddress()
						// linux   : dlsym()

	ICalc* calc = f();

	return calc;
}
*/

int main()
{
	ICalc* calc = load_proxy();
	
	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





