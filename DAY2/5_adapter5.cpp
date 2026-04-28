#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 해결책 #2. 상속이 아닌 포함

template<typename T> 
class stack   : private std::list<T> 
{
public:

	void push(const T& e) { std::list<T>::push_back(e); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()            { return std::list<T>::back();}
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(10); 
}
