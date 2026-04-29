#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();	// 이순간 DLL 내부의 create() 가 호출되고
								// new Calc() 로 Proxy 객체가 만들어집니다.
								// 더이상 사용하지 않으면 delete 해야 하지 않을까요 ?

	int n1 = calc->Add(10, 20);
	
	delete calc; // 이렇게 해도 될까요 ?
	// 안전하지 않습니다. 
	// dll 과 exe 는 다른 컴파일러로 빌드 될 수 있고, 버전이 다를수도 있습니다.

	// 해결책
	// => DLL 내부에서 할당한 메모리는 DLL 내부에서 해제 해야 합니다.
	
}





