#pragma once

// reference couting 기반으로 수명을 관리한다면
// 참조계수용 함수는 반드시 인터페이스에 있어야 합니다.

struct IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
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
