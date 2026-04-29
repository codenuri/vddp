#pragma once

// ICalc.h 헤더로 분리
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
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