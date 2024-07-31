#include <list>

class MyList : public std::list<int> 
{
public:
	using std::list<int>::list; // std::list<int> : 클래스 이름
								// list           : 생성자 이름
};

int main()
{
//	std::list<int> s1 = {1,2,3};
	MyList s1 = {1,2,3};
}
