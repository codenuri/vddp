#define USING_GUI
#include "cppmaster.h"

// remoteproxy1.cpp 를 사용하면
// #1. client 개발자가 모두 IPC 기술을 알아야 합니다
// #2. 서버에서 오류 발생시 각각의 client 에서 에러를 처리해야 합니다.
// #3. 덧셈은 1, 뺄셈은 2 같은 명령 코드를 외워야 합니다.

// 위와 같은 문제를 해결하기 위해
// 원격지 서버를 대신하는 프록시를 사용합니다.
class Calc
{
	int server;
public:
	Calc() {}

	int Add(int a, int b) { return ? ; }
	int Sub(int a, int b) { return ? ; }
};



int main()
{
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





