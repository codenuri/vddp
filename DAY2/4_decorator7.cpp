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
public:
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello"); 


	ZipDecorator zd(&fs); 
	zd.write("hello");	


	EncryptDecorator ed(&zd);
	ed.write("hello"); 
}
