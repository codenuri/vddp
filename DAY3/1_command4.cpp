#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};


struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// 도형을 추가하는 명령은 "유사한 코드가 많이" 있습니다.
// 이 경우 기반 클래스로 공통의 코드를 제공합니다.
class AddCommand : public ICommand 
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back( create_shape() ); } 
	bool can_undo() override { return true; }
	void undo() override 
	{
		if ( v.empty() ) return ;
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
	// 아래 코드 는 결국 변하는 것을 가상함수로 분리하고, 
	// 파생 클래스에서 변하는 것을 구현하므로 "template method" 패턴과 동일합니다.
	// 그런데, 변하는 것이 하는 일이 "알고리즘의 변경" 이 아닌 객체의 종류(타입)을 결정

	// 이 경우는 "factory method" 라는 별도의 이름을 사용합니다.

	// factory method : 객체를 만들기 위한 인터페이스(가상함수)를 제공하고 사용하지만 
	//                  실제 어떤 종류(타입)의 객체를 만들지는 파생 클래스가 결정
	virtual Shape* create_shape() = 0;
};

class AddRectCommand : public AddCommand 
{
public:
	AddRectCommand(std::vector<Shape*>& v) : AddCommand(v) {}

	Shape* create_shape() override { return new Rect;}
};


class AddCircleCommand : public AddCommand 
{
public:
	AddCircleCommand(std::vector<Shape*>& v) : AddCommand(v) {}

	Shape* create_shape() override { return new Circle;}
};





class DrawCommand : public ICommand 
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override 
	{ 
		for ( auto s : v )
			s->draw();
	} 

	bool can_undo() override { return true; }
	void undo() override { system("cls");	}
};





int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> undo_stack; 

	ICommand* command = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) 
		{
			command = new AddRectCommand(v);
			command->execute();				
			
			undo_stack.push(command);		
		}
		else if (cmd == 2) 
		{
			command = new AddCircleCommand(v); 
			command->execute();				 			
			undo_stack.push(command);			
		}
		else if (cmd == 9)
		{
			command = new DrawCommand(v); 
			command->execute();				 			
			undo_stack.push(command);	
		}
		else if ( cmd == 0 )
		{
			if ( !undo_stack.empty() )
			{
				command = undo_stack.top();
				undo_stack.pop();

				if ( command->can_undo() )
				{
					command->undo();

					delete command; 
				}
			}
		}
	}
}






