
// 디자인 패턴을 학습하다 보면, 다양한 패턴이 유사해 보이는 경우가 있습니다.
// => 아래 2개 클래스는 구현이 유사합니다.

class ZipDecorator : public Stream 
{
	Stream* origin; 
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s)
	{
		std::string data = "[ " + s + " ] 압축됨"; // [ hello ] 압축된
		origin->write(data);
	}
};


class ObjectAdapter : public Shape 
{
	TextView* origin; 
public:
	ObjectAdapter(TextView* s) : origin(s) {}

	void draw() override 
	{
		origin->show();
	}
};

// 어떤 패턴들이 유사해 보인다면 "의도"를 생각하세요

FileStream fs("a.txt");
ZipDecorator zd(&fs);
fs.write("hello");
zd.write("hello");

TextView tv("hello");
ObjectAdaptor oa(&tv);
tv.show();
oa.draw();