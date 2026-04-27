// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& name, int age) : name(name), age(age) {}
};
// 아래 주석대로 만들어 보세요
// 1. Person 에서 상속 받는 Student 만들어 보세요
// 2. Student 에 int id 멤버 추가해 보세요
// 3. Student 생성자 만들어서 초기화해 보세요
// 4. main 에서 Student 객체 생성해 보세요

class Student : public Person
{
	int id;
public:
	// 사용자 코드					// 컴파일러 변경한 코드
	//Student(int id) : id(id) { }	// Student(int id) : Person(), id(id) { }
									//                    ^ 이 부분에서 에러

	// 해결책 : Person 의 생성자를 명시적으로 호출해야 합니다.
	// 이름, 나이, id 를 인자로 받아서
	// 이름, 나이 => 기반 클래스 생성자에 전달
	// id => 자신의 멤버를 초기화
	Student(const std::string& name, int age, int id) 
		: Person(name, age), id(id) {}
};

int main()
{
	Student s1("Bob", 20, 12345);

	Person p1("Alice", 30);

//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
}


