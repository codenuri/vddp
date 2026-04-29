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
	Image* img1 = Image::create("www.naver.com/a.png"); // 이순간 새로운 Image 객체 생성
	img1->draw();

	Image* img2 = Image::create("www.naver.com/a.png"); // a.png 그림을 위한 객체는 이미 생성됨
														// 반환된 객체는 위에서 만든 객체
	img2->draw();

	std::cout << img1 << std::endl;
	std::cout << img2 << std::endl;

	// 아이폰 개발에 사용하는 Cocoa Library 가 위처럼 되어 있습니다.
	// Swift 언어	
}



