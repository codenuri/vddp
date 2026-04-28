#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 해결책 #1. private 상속 문법 사용
// => C#, Java, Python 등 에서는 볼수 없는 C++ 언어 만의 문법
// => 많은 C++ 개발자 분들이 잘 모르는 문법
/*
class Base 
{
public:
	void foo() {}
};

class A : public Base  // Base 의 모든 멤버를 동일한 접근 지정자로 상속
{
};
A a;
a.foo(); // ok

class B : private Base  // Base 의 모든 멤버는 B 에 상속되면서 private 으로 변경된다
{
};
B b;
b.foo(); // error. private
		 // 즉, foo() 는 B의 내부에서만 사용가능
*/		 

// private 상속의 디자인 적인 의미
// => 기반 클래스로 부터 구현은 물려 받지만(파생 클래스가 내부적으로는 사용)
// => 인터페이스를 물려받지는 않겠다(외부 노출하지 않겠다.)
// => 위 코드에서 foo() 는 B의 내부에서만 사용하겠다는 의도.


template<typename T> 
//class stack : public std::list<T> 
class stack   : private std::list<T> 
{
public:
	// std::list 의 모든 함수는 stack 내부에는 사용가능
	// 하지만 외부에서는 사용할수 없음.
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()            { return std::list<T>::back();}
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(10); // error. private 상속이므로
					  // std::list 의 모든 함수는 stack 객체를 통해서는 private 멤버 
}
