#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();	// 결국 이코드는
								// DLL 내부의 create()를 호출하고
								// create()에서는 "new" 사용합니다.
								// "delete" 가 필요하지 않을까요 ?

	delete calc; // 이렇게 해도 될까요 ??


}





