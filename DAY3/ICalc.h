#pragma once

// ICalc.h 로 옮기세요
struct ICalc
{
	virtual int Add(int, int ) = 0;
	virtual int Sub(int, int ) = 0;
	virtual ~ICalc() {}
};
