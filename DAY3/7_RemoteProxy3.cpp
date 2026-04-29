#define USING_GUI
#include "cppmaster.h"

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};


class Calc : public ICalc 
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// 위와 같은 Calc Proxy 는 누가 만들게 될까요 ?
// 1. server 제작자 <= 정답
// 2. client 제작자

int main()
{
	// Client 개발자가 아래처럼 Proxy 이름을 직접 사용하면
	// 강한 결합(tightly coupling) 이 됩니다.
	// => 새로운 Proxy 가 등장하면 아래 코드는 수정되어야 합니다
	// Calc* calc = new Calc();

	// 클라이언트 에서는 Proxy 사용시 인터페이스를 사용한 약한 결합으로 사용해야 합니다

	ICalc* calc = new ? ; // 어떻게 해야 할까요 ??
						  // => 다음 소스에서 해결

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;
}





