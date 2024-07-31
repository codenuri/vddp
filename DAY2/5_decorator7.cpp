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

// 중첩된 기능 추가를 위해서는 FileStream 과 Decorator 는
// 공통이 기반 클래스 필요 - Stream
class ZipDecorator : public Stream 
{
	FileStream* stream;
public:
	ZipDecorator(FileStream* stream) : stream(stream){}

	void write(const std::string& s) override 
	{
		auto data = "[ " + s + " 압축됨 ]";
		
	}
};


int main()
{

	FileStream fs("a.txt");
	fs.write("hello");

	ZipDecorator zd(&fs);
	zd.write("hello"); 	// 1. 데이타를 압축하고 <== 추가된 기능
						// 2. fs.write(압축된데이타)

	EncryptDecorator ed(&zd);
	ed.write("hello"); 	// 1. 데이타를 암호화 하고
						// 2. zd.write(암호화된데이타)
}
