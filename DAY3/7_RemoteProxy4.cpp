#define USING_GUI
#include "cppmaster.h"

// remoteproxy4.cpp 

// Client 제작자는 Server 제작자에게 2개의 파일을 받아야 합니다.
// #1. ICalc.h       : 인터페이스 헤더 파일
// #2. CalcProxy.dll : Proxy 클래스가 구현된 DLL 파일

#include "ICalc.h"

/*
ICalc* load_proxy()
{
	// #1. DLL 을 Load 
	void* addr = ec_load_module("CalcProxy.dll");
				// windows: LoadLibrary,   
				// linux  : dlopen

	// #2. DLL 안에 있는 약속된 함수(create) 의 주소 얻기
	using F = ICalc * (*)(); 

	F f = (F)ec_get_function_address(addr, "create");
				// windows : GetProcAddress
				// linux   : dlsym

	// #3. DLL 안의 약속된 함수인 create 를 호출해서 proxy 객체 얻기
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





