#include <iostream>
#include <list>
#include <vector>
#include <deque>

// private 상속 : "상속" 이므로 기반 클래스의 가상함수를 override 할수 있다.
// 포함         : 상속이 아니므로 가상함수 override 할수 없다.



// 해결책 #2. 상속 대신 포함

template<typename T>
class stack 
{
	std::list<T> c;
public:
	void push(const T& e)  { c.push_back(e);}
	void pop()             { c.pop_back();}
	T&   top()             { return c.back();}
};
int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(20); 	// error. 이런 이름의 멤버 함수 자체가 없다!
}
