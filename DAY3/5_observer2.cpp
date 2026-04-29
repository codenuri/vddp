#include <iostream>
#include <vector>

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};

// Table 에서 다루는 데이타의 형태와 상관없이
// 관찰자 패턴 자체의 로직은 변하지 않습니다.
// 변하지 않은 관찰자 패턴의 로직은 기반 클래스로 제공합니다

class Subject 
{
	std::vector<IGraph*> v;	
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->update(data);
	}
};

// 이제 다양한 형태의 Table 을 설계 하는데,
// 관찰자 패턴이 필요하면 Subject 에서 상속 받으면 됩니다.
class Table : public Subject 
{
	int value; 
public:
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
	void update(int n) override
	{
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





