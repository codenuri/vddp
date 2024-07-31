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
	virtual bool can_undo() { return false;}
	virtual void undo() {} 
	virtual ~ICommand() {}
};


class AddCommand : public ICommand 
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void execute()  override { v.push_back( create_shape() );   }
	bool can_undo() override { return true;}
	void undo() override 
	{
		Shape* s = v.back();  	
		v.pop_back();			
		delete s;
	}

	// 객체를 생성하기 위한 인터페이스를 제공하고, 사용하지만
	// 어떤 타입의 객체를 만들지는 파생 클래스가 결정한다.
	// "factory method" 패턴
	// => template method 와 동일한 모양이지만
	//    가상함수가 하는 일이 알고리즘(정책)의 변경이 아닌
	//    객체의 타입을 결정!!
	virtual Shape* create_shape() = 0;
};

class AddRectCommand : public AddCommand
{
public:
	// 파생 클래스 만들때 생성자 인자로 받은것을
	// 기반 클래스로만 전달하는 생성자를 만드는 경우가 많습니다.
	// => 아래 처럼
//	AddRectCommand(std::vector<Shape*>& v) : AddCommand(v) {}

	// 이렇때는 C++11 의 생성자 상속 문법을 사용하면 편리합니다.
	using AddCommand::AddCommand;	// 클래스이름::생성자이름
	

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

	void execute()  override 
	{ 
		for( auto s : v) s->draw();	
	}

	bool can_undo() override { return true;}

	void undo() override 
	{
		system("cls");
	}
};

// 여러 명령을 보관했다가 한번에 실행하는 매크로
class MacroCommand  : public ICommand  // Composite 패턴
{
	std::vector<ICommand*> v;
public:
	void add(ICommand* cmd) { v.push_back(cmd);}

	void execute()
	{
		for( auto cmd : v)
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

	mc1->execute();


	MacroCommand* mc2 = new MacroCommand;

	mc2->add( new AddRectCommand(v));
	mc2->add( mc1 ); // ?
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
			if ( ! undo_stack.empty() )
			{
				command = undo_stack.top();
				undo_stack.pop();

				if ( command->can_undo() )
				{
					command->undo();
				}

				delete command; 
			}
		}
	}
}





