// protected 생성자를 사용하는 의도
// => 자신의 객체는 만들수 없지만(추상적인 개념을 모델링한것)
//    파생 클래스의 객체는 만들수 있도록 하는 것 

class Animal
{
//public:			// A, B 모두 에러 아님
//private:			// A, B 모두 에러

protected:		// ?
	Animal() {}
};

class Dog : public Animal
{
public:
	Dog() {}	// Dog() : Animal() {}	
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// A  error
	Dog    d;	// B  ok
}



