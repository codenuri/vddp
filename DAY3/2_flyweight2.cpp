// 1_Flyweight - 167
#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:	
	void draw() { std::cout << "Draw " << image_url << std::endl; }

	// 자신의 객체를 생성하는 static 멤버 함수
	// => 모든 Image 객체의 생성이 한곳에만 이루어 집니다.
	// => 그럼, 여기서 만들어진 모든 객체를 관리 할수 있습니다.
	// => map 같은 자료구조에 보관

	inline static std::map<std::string, Image*> image_map;

	static Image* create(const std::string& url)
	{
		Image* img = nullptr;

		// url 에 해당하는 Image 객체가 이미 생성되었는지 조사
		auto it = image_map.find(url); 
		
		if ( it == image_map.end() )
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else 
		{
			img = it->second;
		}
		return img;
	}
};

int main()
{
	Image* img1 = Image::create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = Image::create("www.naver.com/a.png");
	img2->draw();

}



