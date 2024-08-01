// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"

// 아래 처럼 만들면

// 1. 모든 클라이언트 개발자가 IPC 기술을 몰라도 됩니다.

// 2. 서버 장애시 모든 클라이언트에서 각각 처리할 필요없이, proxy 처리하면됩니다.

// 3. 1, 2라는 명령 코드 대신, Add, Sub 사용

// 4. 자주 사용되는 명령에 대한 캐쉬 기능 추가 가능. 

// 서버를 대신하는 Proxy 를 만듭니다.

class Calc 
{
	int server;
public:
	Calc() {  server = ec_find_server("Calc");  }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b);}
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b);}
};

int main()
{
	Calc* calc = new Calc;
	
	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





