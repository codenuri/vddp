// 디자인 패턴을 계속 공부하면, 여러개 패턴이 동일(유사)해 보이는 경우가 있습니다.
// 이럴때는 "의도" 를 생각하세요

// object adapter 코드와 decorator 코드는 매우 유사해 보입니다.

// ZipDecorator 복사해 오세요. 사용하는 코드도 복사
class ZipDecorator : public Stream 
{
	Stream* stream;
public:
	ZipDecorator(Stream* stream) : stream(stream){}

	void write(const std::string& s) override 
	{
		auto data = "[ " + s + " 압축됨 ]"; // 추가된 기능

		stream->write(data); // 기존 객체의 기능		
	}
};

FileStream fs("a.txt");
fs.write("hello");

ZipDecorator zd(&fs);
zd.write("hello");

// ObjectAdapter 복사해 오세요. 사용하는 코드도
class ObjectAdapter : public Shape 
{
	TextView* tv; 	
public:
	ObjectAdapter( TextView* tv) : tv(tv) {}

	void draw() override 
	{
		tv->show();
	}
};

TextView tv("hello");
tv.show();
ObjectAdapter oa(&tv);
oa.draw();
