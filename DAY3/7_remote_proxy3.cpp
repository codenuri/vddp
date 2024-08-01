#define USING_GUI
#include "cppmaster.h"

struct ICalc
{
	virtual int Add(int, int ) = 0;
	virtual int Sub(int, int ) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc 
{
	int server;
public:
	Calc() {  server = ec_find_server("Calc");  }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b);}
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b);}
};

// 위 Proxy(Calc) 클래스의 제작자 : Server 제작자
// 위 Proxy(Calc) 클래스의 사용자 : Client 제작자


int main()
{
	// 아래 처럼 만들면 강한 결합이므로
	// Proxy 가 새로 배포되면 코드가 수정되어야 합니다
	// Calc* calc = new Calc;

	// 약한 결합으로 사용해야 합니다
	ICalc* calc = new ?;
	
	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





