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
//	DNS dns; 	
	DNSProxy dns;

//	std::cout << dns.get_ip("www.samsung.com") << std::endl;
	std::cout << dns.get_ip("www.naver.com") << std::endl;
}

// proxy : 다양한 용도의 대행자를 만드는 패턴

// virtual proxy : 위와 같은 캐쉬 기능을 제공하는 proxy
// remote proxy : 원격지 서버를 대행하는 proxy

// decorator : 객체에 기능의 추가. original 객체도 계속 사용가능
//FileStream fs;
//ZipDecorator zd(&fs);
//zd.write("aaa");
//fs.write("aaa"); // original 객체도 계속 사용가능

// proxy : original 객체를 사용하지 말고 proxy 를 사용하라는 의도
//         DNS 사용하지 말고 DNSProxy 사용하라는 것
