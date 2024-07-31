#include <iostream>
#include <vector>

class NotImplemented{};

class Shape 
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c;}

	void draw() 
	{
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}



	// 가상함수 : override 하지 않으면 기본 구현 제공한다는 의미
	// 순수가상함수 : 반드시 override 해서 파생클래스가 구현 제공하라는 의미

	virtual void draw_imp() = 0;


//	virtual Shape* clone()  = 0; // 이렇게 해도 좋고
	
	// 아래 처럼 구현하기도 합니다. (파이썬, 자바 등에서 많이 사용)
	// 1. 구현부을 제공하고 사용하면 ok
	// 2. 구현부을 제공하지 않고 사용하지 않고 사용도 안하면 ok
	// 3. 구현부을 제공하지 않고 사용하면 예외 발생
	virtual Shape* clone()  { throw NotImplemented();}

	// 아래 함수도 위처럼 "=0"  또는 "예외" 로 해도 되고 
	// C 처럼 실패를 나타내는 값을 반환해도 될거 같습니다.
	// => 매뉴얼에 "get_area 호출시 -1이 나오면 면적 구할수 없음" 이라고 명시
	virtual int get_area()    { return -1;}
};




class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n";}

	// 공변 반환의 법칙
	// => 가상함수 override 시에 반환 타입을 변경해도 됩니다.
	// => 단, 상속관계의 타입으로만
	// => 아래 clone 은 Shape* 반환 보다는 Rect* 반환이 좋습니다.
	Rect* clone() override { return new Rect(*this); }	
};
// Rect* r = new Rect;
// Shape* s = r->clone(); // 이렇게 Shape* 로 받으면 Rect 고유 멤버 접근
//							안됨
class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Circle\n";}

 	Circle* clone() override { return new Circle(*this); }		
};

int main()
{
	std::vector<Shape*> v;

	while( 1 )
	{
		int cmd;
		std::cin >> cmd;

		// 생각해 볼 문제 : 객체의 생성을 OCP 를 만족하게 할수 없을까 ?
		//                새로운 도형이 추가되어도 아래 코드가 수정되지 않게..
		// => "factory" 패턴을 사용하면 됩니다. 3일차에 배웁니다.
		if      ( cmd == 1 ) v.push_back( new Rect);
		else if ( cmd == 2 ) v.push_back( new Circle);
		else if ( cmd == 9 )
		{
			for ( auto s : v)
				s->draw();	// 새로운 도형 추가시 변경 안됨. OCP 만족
		}
		else if ( cmd == 8 )
		{
			std::cout << "몇 번째 도형을 복사할까요 >> ";
			int k;
			std::cin >> k;

			v.push_back( v[k]->clone() ); // 새로운 도형 추가시 변경 안됨. OCP 만족
		}
	}
}


