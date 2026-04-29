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

	// 외부에서는 Image 객체를 만들수 없어야 하지만(private 생성자)
	// 공장에서는 만들수 있어야 한다
	friend class ImageFactory;
		// => ImageFactory 클래스에서는 
		// => Image 의 private 에 접근 가능하게 해달라는 것
};

// flyweight2.cpp 의 Image 클래스
// => 1. 인터넷에서 그림을 다운로드해서 그리는 기능
// => 2. 자신(Image)의 객체를 생성하고 공유하는 기능

// SRP : Single Responsibility Principle
// => 하나의 클래스는 하나의 기능만 가지는 것이 좋다.

class ImageFactory
{
	std::map<std::string, Image*> image_map;
public:
	Image* create(const std::string& url)
	{
		Image* img = nullptr;

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
	// #1. Image 객체를 만드는 공장을 먼저 만들고
	ImageFactory factory;

	// #2. 공장에서 Image 객체를 생성한다.
	Image* img1 = factory.create("www.naver.com/a.png"); 
	img1->draw();

	Image* img2 = factory.create("www.naver.com/a.png"); 
	img2->draw();

	std::cout << img1 << std::endl;
	std::cout << img2 << std::endl;

}



