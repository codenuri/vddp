#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc1 = load_proxy();	

	calc1->AddRef();  // 규칙 #1. proxy 를 만든 후에는 참조계수 증가

	ICalc* calc2 = calc1;
	calc2->AddRef();  // 규칙 #2. proxy 포인터 복사후 참조계수 증가

	calc1->Release();	// 규칙 #3. 포인터 사용후에는 참조계수 감소

	std::cout << "---------------\n";

	calc2->Release();

	std::cout << "---------------\n";
}





