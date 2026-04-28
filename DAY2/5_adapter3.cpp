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

int main()
{
	stack<int> s;
	s.push(10);
}
