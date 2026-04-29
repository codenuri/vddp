// 32bit로 컴파일 해야 합니다.
// visual studio 위에 콤보에서
// "x64" 대신 "x86"을 선택하세요.
// 
// Server1.cpp
#define USING_GUI
#include "cppmaster.h" 

class Server
{
public:
	int Add(int a, int b) { return a + b; }
	int Sub(int a, int b) { return a - b; }
};
Server server;

int handler(int code, int a, int b)
{
	printf("클라이언트 접속 : %d, %d, %d\n", code, a, b);
	switch (code)
	{
	case 1: return server.Add(a, b); // handler 함수의 반환 값은
	case 2: return server.Sub(a, b); // client 에게 전달됩니다.
	}
	return 0;
}

int main()
{
	// 현재 프로세스를 IPC 서버로 동작
	ec_start_server("Calc",    // 서버 이름, Client 는 이 이름으로 서버를 찾아야 합니다.
					&handler); // Client 접속시 handler 호출해 달라
							   // Client 는 int 값 3개를 서버에 전달
}




