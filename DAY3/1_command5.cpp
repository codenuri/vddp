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
//---------------------------
// 여러개의 명령을 보관했다가 한번에 실행하는 Macro 명령을 만들어 봅시다.
// MacroCommand 는 일반 명령을 보관하지만 MacroCommand 자체도 보관해야 한다.
// => MacroCommand 와 일반 명령은 공통의 기반 클래스(ICommand) 가 있어야 한다
// => Composite 패턴
class MacroCommand : public ICommand    //<== 핵심 Composite 패턴
{
	std::vector<ICommand*> v;
public:
	void add(ICommand* cmd) { v.push_back(cmd);}

	void execute()
	{
		for (auto cmd : v )
			cmd->execute();
	}
};
int main()
{
	std::vector<Shape*> v;

	MacroCommand* mc1 = new MacroCommand;
	mc1->add( new AddRectCommand(v));
	mc1->add( new AddCircleCommand(v));
	mc1->add( new DrawCommand(v));

	mc1->execute(); // 자신이 보관하는 모든 명령을 한번에 실행


	MacroCommand* mc2 = new MacroCommand;
	mc2->add( new AddRectCommand(v));
	mc2->add( mc1 ); // 매크로 명령에 다시 매크로 명령 포함

	mc2->execute();




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






