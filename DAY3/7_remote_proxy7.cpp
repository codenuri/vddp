#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// "raw pointer" 를 사용하지 말고
// "raw pointer" 의 대행자(proxy) 를 제공합니다

// 흔히 이야기 하는 "smart pointer"

template<typename T>
class sp 
{
	T* obj;
public:
	sp(T* p = nullptr ) : obj(p) { }
	sp(const sp& other) : obj(other.obj) { }
	~sp() {}
};

int main()
{
	sp<ICalc> calc1 = load_proxy();
	sp<ICalc> calc2 = calc1;
}


int main()
{
	ICalc* calc1 = load_proxy();	
	calc1->AddRef();  

	ICalc* calc2 = calc1;
	calc2->AddRef();  

	calc1->Release();	
	std::cout << "---------------\n";
	calc2->Release();
	std::cout << "---------------\n";
}





