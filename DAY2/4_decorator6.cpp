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

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	// File 에 쓸때 암호화 해서 쓰는 기능이 필요 합니다.
	// 최선의 디자인을 생각해 봅시다.

	// 방법 #1. 사용자 직접 데이타를 암호화 한후에 파일에 쓴다.
	// => 매번 사용자가 해야 한다면 불편합니다.
	// => 라이브러리에서 제공해 주어야 합니다
	

	// 방법 #2. 상속을 사용한 암호화 기능 추가
	//          FileStream 에서 파생된 EncryptFileStream 클래스 추가
	// 단점 #1. NetworkStream, PipeStream 등 모든 Stream 클래스의 파생 클래스가 필요하다.
	// 단점 #2. 암호화 외에 압축 기능도 필요 하고, 
	//          암호화 압축이 동시에 필요하면 - 다중 상속

	// 방법 #3. Decorator 패턴을 사용하면 어떨까 ??

	fs.write("hello"); // 그냥 파일에 쓰기


	ZipDecorator zd(&fs); // fs 뿐 아니라 NetworkStream, PipeStream 모두 가능

	zd.write("hello");	// 1. "hello" 를 먼저 압축 - 기능 추가
						// 2. origin.write(압축된데이타)
						//	  ^ 파일, 네트워크, 파이프 등에 압축된 데이타 쓰기

	EncryptDecorator ed(&zd);

	ed.write("hello"); // 1. "hello" 를 암호화
					   // 2. origin.write(암호화된데이타) 인데, 현재 origin 은 zd
					   //    => 따라서, 암호화된 데이타를 압축해서
						//      파일에 쓰기

						// 실제 구현은 다음소스. 
}
