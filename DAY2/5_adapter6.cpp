#include <iostream>
#include <list>
#include <vector>
#include <deque>


template<typename T, typename C = std::deque<T> > 
class stack 
{
	C c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop()            { c.pop_back(); }
	T&   top()            { return c.back();}
};

int main()
{
	stack<int, std::list<int>>   s1; // list   함수이름을 stack 처럼 사용가능하게 변경
	stack<int, std::vector<int>> s2; // vector 함수이름을 stack 처럼 사용가능하게 변경
	
	stack<int> s; // 내부적으로 deque 사용
	s.push(10);

}
