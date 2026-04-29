#pragma once

// ICalc.h 


// 참조계수 기반으로 객체의 수명을 관리 한다면
// 참조계수 관련 함수는 인터페이스에도 있어야 합니다.

// 서버의 종류에 관계 없이 참조 계수 함수는 항상 동일 합니다.
struct IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ~IRefCount() {}
};


struct ICalc : public IRefCount
{
//	virtual void AddRef() = 0;
//	virtual void Release() = 0;

	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

// LedServer 에 대한 Proxy
struct ILedServer : public IRefCount
{
	virtual int LedOn() = 0;
	virtual int LedOff() = 0;
	virtual ~ILedServer() {}
};











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