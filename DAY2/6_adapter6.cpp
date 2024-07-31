#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 핵심 :  adapter 패턴과 Policy Base Design 의 결합

template<typename T, typename C = std::deque<T> > 
class stack 
{
	C c;
public:
	inline void push(const T& e)  { c.push_back(e);}
	inline void pop()             { c.pop_back();}
	inline T&   top()             { return c.back();}
};

#include <stack> // C++ 표준 stack
				 // 이 안의 코드가 위와 거의 동일하게 되어 있습니다.
				 // 흔히 "stack adapter" 라고 부릅니다.
int main()
{	
	stack<int, std::vector<int>> s1;
	stack<int, std::list<int>> s2;

	stack<int> s;
	s.push(10);

}
