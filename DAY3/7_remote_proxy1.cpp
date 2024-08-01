// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"

// 아래 처럼 만들면

// 1. 모든 클라이언트 개발자가 IPC 기술을 알아야 합니다.

// 2. 서버 장애시 모든 클라이언트에서 각각 처리해야 합니다.

// 3. 1, 2라는 명령 코드를 외워야 합니다

// 4. 자주 사용되는 명령에 대한 캐쉬가 없습니다.

int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





