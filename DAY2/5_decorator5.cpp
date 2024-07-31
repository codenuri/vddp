#include <iostream>

// 모든 Stream 의 사용법이 동일하게 하기 위해
// 인터페이스로 약속
struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}

	// 이외에도 read, flush, is_open 등의 다양한 함수를 여기서 약속
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

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

/*
	NetworkStream ns("100.100.100.100", 3000);
	ns.write("hello");


	PipeStream ps("mynamedpipe");
	ps.write("hello");
*/
}
