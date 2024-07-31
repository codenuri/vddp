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

// 활용 #2. 동종 객체를 처리하는 함수 만들기.
//void NewYear(Dog* pDog) // Dog 객체만 받겠다는 의도
void NewYear(Animal* p)   // 모든 동물 객체를 받겠다는 의도
{
	++(p->age); 
	
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











