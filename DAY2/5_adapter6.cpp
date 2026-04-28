#include <iostream>
#include <list>
#include <vector>
#include <deque>


template<typename T, typename C = std::deque<T> > 
class stack 
{
	C c;
public:
	inline void push(const T& e) { c.push_back(e); }
	inline void pop()            { c.pop_back(); }
	inline T&   top()            { return c.back();}
};

#include <stack> // 이 안에 있는 C++ 표준 std::stack 이 위 코드와 거의 유사합니다.
				 // "adaptor 패턴 + policy base design" 으로 만들어진 멋진 설계 입니다.
				 // policy base design : 어떤 컨테이너를 사용할지 템플릿 인자로 교체
				 // adaptor            : 컨테이너의 함수 이름은 stack 처럼 보이게 변경

int main()
{
	stack<int, std::list<int>>   s1; // list   함수이름을 stack 처럼 사용가능하게 변경
	stack<int, std::vector<int>> s2; // vector 함수이름을 stack 처럼 사용가능하게 변경
	
	stack<int> s; // 내부적으로 deque 사용
	s.push(10);

}
