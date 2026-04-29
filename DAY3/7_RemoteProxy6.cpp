#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// Proxy 객체가 참조 계수로 관리 되므로 아래 처럼 사용해야 합니다.

int main()
{
	ICalc* calc1 = load_proxy();	
	calc1->AddRef();	// 규칙 #1. proxy 생성후 참조 계수 1 증가

	ICalc* calc2 = calc1;
	calc2->AddRef();	// 규칙 #2. proxy 포인터를 복사할 때마다 참조 계수 1 증가

	int n1 = calc1->Add(10, 20);

	calc1->Release();	// 규칙 #3. proxy 사용이 끝나면 참조 계수 1 감소
	
	std::cout << "---------------------------------\n";
	calc2->Release();	// 참조 계수가 0 이 되면 proxy 객체가 스스로 파괴 됩니다.
	std::cout << "---------------------------------\n";
}





