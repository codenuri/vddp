#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// www.naver.com : URL
// 100.100.100.100 : IP


// Domain Name Server : url => ip 로 변경
struct IDNS
{
	virtual std::string get_ip(const std::string& url) = 0;
	virtual ~IDNS() {}
};
class DNS : public IDNS
{
	std::string ip;
public:
	std::string get_ip(const std::string& url) 
	{
		std::cout << "서버에 접속해서 "
				  << url << " 에 대한 IP 정보를 얻어오는 중\n";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		ip = "100.100.100.100";		
	}
};
int main()
{
	DNS dns;
	std::cout << dns.get_ip("www.samsung.com") << std::endl;
}