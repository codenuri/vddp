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

//	std::cout << dns.get_ip("www.samsung.com") << std::endl;
	std::cout << dns.get_ip("www.naver.com") << std::endl;
}

// Proxy 패턴
// => 다양한 의도로 "기존에 사용하던 클래스" 를 "대신" 하는 클래스를 만드는 것

// 1. 성능 향상을 위한 캐쉬 도입
// 2. 보안을 위한 proxy - id, pass 검증
// 3. remote 서버에 대한 대행자 - 다음 예제 
// 등... 

// 결국 DNS 기능에 "캐쉬" 기능 추가 이므로 "decorator" 패턴 아닌가요 ?

// decorator 패턴 : origin 을 계속 사용할수 있다.
FileStream fs("a.txt");
ZipDecorator zd(&fs); // fs 에 압축기능 추가

zd.write("hello");    // 이렇게 하면 기능을 추가해서 사용(압축후 쓰기)
fs.write("hello");    // 기능 추가 이전의 원래 기능 사용


// proxy 패턴 : "기능의 추가" 가 본질이 아니라 "대신하는 것" 을 만드는 것
//DNS dns;		// 이 클래스 대신
CacheDNS dns; 	// 이 클래스 사용해라. 

auto ip = dns.get_ip("www.naver.com");