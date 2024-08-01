#pragma once

// ICalc.h 로 옮기세요
struct ICalc
{
	virtual int Add(int, int ) = 0;
	virtual int Sub(int, int ) = 0;
	virtual ~ICalc() {}
};



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
