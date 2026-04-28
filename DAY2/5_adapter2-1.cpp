
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

fs.write("hello"); // 원본 객체 사용
zd.write("hello"); // 사용법이 원본 객체와 동일합니다
				   // => 즉, 인터페이스는 변경되지 않고, 기능(압축)을 추가한것
				   // => decorator 패턴

TextView tv("hello");
ObjectAdaptor oa(&tv);

tv.show();	// 원본 객체 사용
oa.draw();	// 사용법(인터페이스)가 변경된것, 기능은 동일
			// => 기능은 동일한데, 인터페이스를 변경한것
			// => adaptor 패턴