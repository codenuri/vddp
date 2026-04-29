#include <iostream>
#include <vector>

class Subject; // 클래스 전방 선언
			   // 클래스 자체가 코드 아래 부분에 있어도 포인터 변수는 만들수 있도록하기 위해

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// 모든 그래프는 자신이 어떤 테이블과 연결되었는지 알아야 한다
	Subject* subject = nullptr;
};



class Subject 
{
	std::vector<IGraph*> v;	
public:
	void attach(IGraph* p) 
	{ 
		v.push_back(p); 
		p->subject = this;
	}

	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->update(data);
	}
};

class Table : public Subject 
{
	int value;
	int data[4] = {1,2,3,4}; 
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
	void update(int n) override
	{
		// Table 에서 자신의 상태가 변경되었다고 통보가 왔으므로
		// 1. 인자로 전달된 데이타 n 만 사용해서 그래프를 update 할수 있다면 사용
		// 2. n 으로 부족하면 Table 에 접근해서 data 을 얻은후 그린다.

		Table* table = static_cast<Table*>(subject);

		int* data = table->get_data();
		
		// data 를 사용해서 그림을 그린다...
		// .... 
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





