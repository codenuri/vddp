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
	
	s.push_front(10); // error. stack 에는 이런 멤버 함수가 없다!
}
