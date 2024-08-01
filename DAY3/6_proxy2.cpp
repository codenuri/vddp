#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Domain Name Server : url => ip 로 변경
struct IDNS
{
	virtual std::string get_ip(const std::string& url) = 0;

	virtual ~IDNS() {}
};
// git 에서 proxy1.cpp 다시 받으세요

class DNS : public IDNS
{
public:
	std::string get_ip(const std::string& url)
	{
		std::cout << "서버에 접속해서 "
				  << url << " 에 대한 IP 정보를 얻어오는 중\n";
				  
		std::this_thread::sleep_for(std::chrono::seconds(3));

		std::string ip = "100.100.100.100";

		return ip;
	}
};

// DNS 대신 사용하기 위한 클래스
class DNSProxy : public IDNS
{
	// static std::map<URL, IP> ip_cache;
public:
	std::string get_ip(const std::string& url)
	{
		if ( url == "www.samsung.com") // url 캐쉬에 있는 찾는 코드라고 가정
		{
			// 캐쉬에 있던 IP 반환
			return "100.100.100.100";
		}
		// 캐쉬에 없으면 실제 "DNS" 클래스 사용
		DNS dns;
		
		return dns.get_ip(url);
	}
};
int main()
{
	DNS dns; 

	std::cout << dns.get_ip("www.samsung.com") << std::endl;
}
