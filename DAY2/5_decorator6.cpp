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
	// File 에 쓸때 암호화 해서 쓰는 기능이 필요 합니다.
	// 최선의 디자인을 생각해 봅시다.

	// 방법 #1. 사용자가 직접 암호화 해서 파일에 쓰게 한다.
	// => 매번 이렇게 한다면 불편하다.
	// => 라이브러리가 제공해주는 것이 편리하다.

	// 방법 #2. 상속을 사용한 기능의 추가
	// => FileStream 을 확장해서 암호화 기능이 추가된
	//    EncryptFileStream 을 만들자.

	// 단점 1. NetworkStream, PipeStream 도 모두 파생클래스 만들어서
	//         암호화 기능 추가해야 한다.

	// 단점 2. 압축기능이 필요하면 또 파생 클래스를 만드는데,
	//        압축과 암호화가 모두 필요 하면 ?
	//		=> 다시 파생 클래스(다중상속)을 만들어야 한다.
	
	// => 상속의 단점을 잘 알아두세요
	// => 유연성이 없고, 경직된 디자인이 됩니다.

	// 방법 #3. decorator 패턴을 사용하면 어떨까 ?

	FileStream fs("a.txt");
	fs.write("hello");

	ZipDecorator zd(&fs);
	zd.write("hello"); 	// 1. 데이타를 압축하고 <== 추가된 기능
						// 2. fs.write(압축된데이타)

	EncryptDecorator ed(&zd);
	ed.write("hello"); 	// 1. 데이타를 암호화 하고
						// 2. zd.write(암호화된데이타)
}
