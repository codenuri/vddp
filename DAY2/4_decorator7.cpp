#include <iostream>

struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}
};


class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s) 
	{
		printf("%s 쓰기\n", s.c_str() );
	}
};
//------------------------------------------------------
// FileStream, NetworkStram, PipeStream 등의 다양한 Stream 에 적용가능한(기능추가할수 있는)
// Decorator 들을 제공합니다.
class ZipDecorator : public Stream 
{
	Stream* origin; // [핵심] 외부에 이미 생성된 Stream 객체를 가리킨다.
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s)
	{
		std::string data = "[ " + s + " ] 압축됨"; // [ hello ] 압축된

		// 이제 압축된 데이타를 다양한 Stream 을 사용해서 쓰도록 원본에 전달
		origin->write(data);
	}
};
class EncryptDecorator : public Stream 
{
	Stream* origin; 
public:
	EncryptDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s)
	{
		std::string data = "[ " + s + " ] 암호화"; 		
		origin->write(data);
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello"); 

	ZipDecorator zd(&fs); 
	zd.write("hello");	// 1. "hello" 압축하고 - 추가된 기능
						// 2. fs.write() 에 전달

	EncryptDecorator ed(&zd);
	ed.write("hello");  // 1. "hello" 암호화
						// 2. zd.write() 에 전달
}

// 1. 구글에서 "C# Stream" 검색하세요
// 2. 이미지 보기로 보세요

// C#/Java 의 입출력 이 모두 "Decorator" 패턴으로 설계된것
// Python  의 @ 로 시작하는 요소가 "Decorator" 패턴의 개념을 사용한것 
// => 약간 변형된 형태.. @ 에 대해서 깊이 있게 공부해 보세요.
// => 파이썬에서도 "decorator" 라고 부릅니다. 결국, 동적 기능 추가 입니다.
