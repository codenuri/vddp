// server.zip 압축 풀고
// 안에 있는 server1.cpp 만 DAY3 폴더에 넣으세요

// 32bit로 컴파일 해야 합니다.
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
	case 1: return server.Add(a, b);
	case 2: return server.Sub(a, b);
	}
	return 0;
}
int main()
{
	// IPC 서버로 동작
	ec_start_server("Calc",    // 서버이름
					&handler); // 클라이언트 접속시 호출될 함수
							   // => client 는 3개의 정수를 보내게 됩니다.
}

// 새롭게 command prompt(cmd.exe)
// 실행하고, 

// clsetup.bat
// cl server1.cpp
// server1.exe



