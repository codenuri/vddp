// 1_생성자3.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& name, int age) : name(name), age(age) {}
};
// Person 으로 부터 파생된 Student 만들어 보세요
// 1. int id 추가해 보세요
// 2. 생성자 만들어 보세요
// 3. main 에서 Student 객체 만들어 보세요

class Student : public Person 
{
	int id;
public:
//	Student( int id) : id(id) {}   // Student( int id) : Person(), id(id) {}

	Student( const std::string& name, int age, int id) 
		: Person(name, age), id(id) {}
}; 


int main()
{
	Student s("kim", 30, 3);

//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
}

