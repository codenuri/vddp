#include <iostream>

// 모든 종류의 Stream 클래스들이 지켜야 하는 규칙을 약속한 인터페이스
// (FileStream, NetworkStream, PipeStream)
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
	// 아래 클래스도 있다고 가정해 봅시다.
	NetworkStream ns("100.100.100.100", 3000);
	ns.write("hello");

	PipeStream ps("mynamedpipe");
	ps.write("hello");
	*/
	// 위 3개의 Stream 은 결국 모두 읽고/쓰는 작업을 하는 것
	// 그런데, 대상이 다른 종류(파일, 네트워크, 파이프)
	// => 사용법이 같은것이 편리합니다.
	// => 인터페이스로 함수이름을 약속하면 됩니다. - 현재 소스 윗부분의 Stream 인터페이스
}
