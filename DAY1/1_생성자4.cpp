// protected 생성자 의도
// => 자신은 객체를 만들수 없지만(추상적인 개념을 모델링한 클래스!!)
// => 파생 클래스는 객체를 만들수 있게(구체(concreate) 개념을 모델링한 클래스)

class Animal
{
//public:		// 1, 2 모두 에러 아님
//private:		// 1, 2 모두 에러
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {} // Dog() : Animal() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// 1. error
	Dog    d;	// 2. ok
}



