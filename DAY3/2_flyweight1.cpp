// 1_Flyweight - 167
#include <iostream>
#include <string>
#include <map>


// 속성이 동일한 객체는  공유 할수 있게 하자.
// => 아래 코드에서 동일한 그림을 관리하는 객체는 2개 만들 필요가 없다. 

// Image 클래스 : 인터넷에서 그림을 다운 받아서 화면에 그리는 기능을 제공
class Image
{
	std::string image_url;
public:
	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
	void draw() { std::cout << "Draw " << image_url << std::endl; }
};

int main()
{
	Image* img1 = new Image("www.naver.com/a.png");
	img1->draw();

	Image* img2 = new Image("www.naver.com/a.png");
	img2->draw();

}



