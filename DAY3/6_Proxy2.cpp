#include <iostream>
#include <string>
#include <thread>
#include <chrono>

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

		return ip;
	}
};

// DNS 에 캐쉬 기능을 추가한 새로운 도구를 만들어서
// 사용자들에게 DNS "대신" 사용하게 해봅시다.
class CacheDNS : public IDNS
{
public:
	std::string get_ip(const std::string& url) 
	{
		// #1. 인자로 전달된 url 이 캐쉬에 있는지 먼저 조사
		//     캐쉬에 있다면 캐쉬값 반환
		if ( url == "www.samsung.com") // <= 캐쉬 조사라고 가정
		{
			return "100.100.100.100";
		}

		// #2. 캐쉬에 없다면 원래 "DNS" 클래스 기능을 사용
		// => 3초가 걸리는 오버헤드가 있는 작업
		DNS dns;
		return dns.get_ip(url);
	}
};


int main()
{
	// 이제 사용자에게는 DNS 을 사용하지말고
	// CacheDNS 를 사용하도록 한다.
	// DNS dns;
	CacheDNS dns;

	std::cout << dns.get_ip("www.samsung.com") << std::endl;
}