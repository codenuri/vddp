#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// RemoteProxy6.cpp 처럼 참조계수 수명 규칙을 직접 사용하면
// #1. 규칙 자체가 어렵지는 않지만, 지루한 코드입니다.
// #2. 실수로 규칙을 어기는 경우가 발생할 수 있습니다.


// 참조 계수 규칙을 실수 하지 않도록 만들어 봅시다.
// => 자동으로 참조계수를 관리하는 스마트 포인터 도입
// => 안드로이드 오픈소스 안에 아래와 유사한 클래스가 있습니다.

template<typename T> class sp
{
	T* ptr;
public:
	sp(T* p = nullptr)  : ptr(p)         { if (ptr) ptr->AddRef(); }
	sp(const sp& other) : ptr(other.ptr) { if (ptr) ptr->AddRef(); }
	~sp() { if (ptr) ptr->Release(); }	

	// 스마트 포인터의 핵심
	// => 진짜 포인터 처럼 -> 와 * 연산 자를 사용할수 있어야 한다
	T* operator->() { return ptr; }
	T& operator*()  { return *ptr; }
};

int main()
{
	sp<ICalc> calc1 = load_proxy(); // sp<ICalc> calc1( load_proxy() );
//	calc1->AddRef();	

	sp<ICalc> calc2 = calc1;
	//calc2->AddRef();	

	int n1 = calc1->Add(10, 20);
}







