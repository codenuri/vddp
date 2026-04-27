// upcasting3.cpp
class Animal 
{
public: 
	int age;
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};

// upcast 장점(활용) #2. 동종을 처리하는 함수 만들기 
//void NewYear(Dog* pDog) // Dog 만 전달 받을수 있는 함수
void NewYear(Animal* p)   // 모든 동물(동종)을 전달 받을수 있는 함수
{
	++(p->age); 	

	// 인자로 Dog 객체가 전달되어도 
	// p의 타입이 Animal* 이므로 아래 처럼은 안됨. 
//	p->color = 10; // error
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











