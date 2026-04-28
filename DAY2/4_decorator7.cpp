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
