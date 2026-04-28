#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 해결책 #2. 상속이 아닌 포함
// => std::list 의 멤버 함수는 stack 내부적으로만 사용한다면..
// => 상속 대신 포함이 좋다 
template<typename T> 
class stack 
{
	std::list<T> c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop()            { c.pop_back(); }
	T&   top()            { return c.back();}
};
int main()
{
	stack<int> s;
	s.push(10);
//	s.push_front(10); // error. stack 에는 이런 멤버 함수가 없다!
}

// 핵심 : adaptor 같은 디자인 패턴을 사용시
// 기반 클래스 멤버를 파생 클래스 객체에서도 외부에 노출하려면 상속
// 기반 클래스 멤버를 파생 클래스 내부에서만 사용한다면 포함

// 그러면 "private 상속" 은 언제 사용하나요 ?

// 아래 A, B 는 모두 Sample 의 멤버 함수를 모두 내부적으로만 사용하는 코드 입니다.
/*
class A : private Sample 
{
	// Sample 에 가상함수가 있다면 재정의할 기회가 있다.
public:
	void sample_method() override {}
};

class B 
{
	Sample s;
	// Sample 에 가상함수가 있다면 재정의할 기회가 없다.
};
*/