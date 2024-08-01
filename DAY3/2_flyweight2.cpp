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


	// C++17 inline static 문법
	// => static 멤버 데이타의 외부 선언 없어도 됩니다.
	// => g++ 소스.cpp -std=c++17
	inline static std::map<std::string, Image*> image_map;

	static Image* create( const std::string& url)
	{
		Image* img = nullptr;
		auto it = image_map.find(url);

		if ( it != image_map.end() )
		{
			img = it->second;  	// 맵의 반복자는 std::pair 이고
								// first 는 키값, second 는 value(image*)
		}
		else 
		{
			img = new Image(url);
			image_map[url] = img;
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



