#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// 1. C++ 표준에 list 가 이미 있습니다.
// 2. 그런데, 사용자가 stack 을 요구합니다.(stack 도 있지만, 없다고 가정)

// list 의 함수 이름을 변경해서 stack 처럼 보이게 해 봅시다.
template<typename T>
class stack : public std::list<T>
{
public:
	void push(const T& e)  { std::list<T>::push_back(e);}
	void pop()             { std::list<T>::pop_back();}
	T&   top()             { return std::list<T>::back();}
};

int main()
{
	stack<int> s;
	s.push(10);
}
