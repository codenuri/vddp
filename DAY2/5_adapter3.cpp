#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter

// C++ 표준에 std::list 가 있습니다
// 그런데, 사용자가 stack 을 요구 합니다(이미 있지만 없다고 가정)

// 방법 #1. 새롭게 stack 을 만들자
// 방법 #2. std::list 를 한쪽 방향으로만 사용하면 stack 처럼 보인다. 
//          list 를 활용해서 stack 을 만들자

// list 의 함수 이름(push_back) 을 stack 처럼 보이도록(push) 로 변경해 봅시다.
template<typename T> 
class stack : public std::list<T> 
{
public:
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()            { return std::list<T>::back();}
};

// 위 코드는 결국 실제 stack 기능을 구현한 것이 아니라
// list 의 함수 이름만 stack 처럼 보이도록 만든것 - adaptor 패턴

int main()
{
	stack<int> s;
	s.push(10);

	// 위 코드의 문제점
	// => 사용자들이 아래 처럼 사용할수 있게 됩니다.
	s.push_front(10); // list 로 부터 물려 받게 되므로 사용가능.
					  // stack 처럼 사용하려면 한쪽(뒷방향)으로만 사용해야 한다.
					  // => 다음 소스에서 해결
}
