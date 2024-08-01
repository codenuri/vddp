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
	sp(T* p = nullptr ) : obj(p) { if ( obj != nullptr ) obj->AddRef(); }
	sp(const sp& other) : obj(other.obj) { if ( obj != nullptr ) obj->AddRef();}
	
	~sp() {if ( obj != nullptr ) obj->Release();}

	// -> 와 * 을 연산자 재정의 해서 "raw pointer" 와 동일하게 사용할수 있도록
	T* operator->() { return obj;}
	T& operator*() { return *obj;}

};
int main()
{
	sp<ICalc> calc1 = load_proxy();
	sp<ICalc> calc2 = calc1;

	int n1 = calc1->Add(10, 20);
	int n2 = (*calc1).Add(10, 20);

}

/*
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
*/




