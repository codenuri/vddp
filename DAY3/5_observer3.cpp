#include <iostream>
#include <vector>

class Subject; 	// 클래스 전방 선언
				// 완전한 선언이 없어도 포인터는 만들수 있다.

struct IGraph
{
	virtual void update(int hint, Subject* sender) = 0;
	virtual ~IGraph() {}
};

class Subject 
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int hint)
	{
		for (auto p : v)
			p->update(hint, this);
	}
};

class Table : public Subject
{
	int value; 
	int data[12] = {1,2,3,4};
public:

	int* get_data() { return data;}

	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;	
			notify(value);		
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void update(int n, Subject* sender) override
	{
		// Table 이 변경되었다고 통보가 왔으므로
		// Table 에 접근해서 데이타를 꺼내와서
		// 그래프를 그린다.
	//	int* data = sender->get_data(); // error. sender 는 Subject* 타입

		
		int* data = static_cast<Table*>(sender)->get_data();

		// data 를 사용해서 그린다.


		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};

class PieGraph : public IGraph
{
public:
	void update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};

int main()
{
	Table t;
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	t.edit();
}





