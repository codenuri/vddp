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

class AddRectCommand : public ICommand 
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute()  override { v.push_back(new Rect);   }
	bool can_undo() override { return true;}
	void undo() override 
	{
		Shape* s = v.back();  	// 반환만, 제거 안됨
		v.pop_back();			// 제거
		delete s;
	}
};

class AddCircleCommand : public ICommand 
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute()  override { v.push_back(new Circle);   }
	bool can_undo() override { return true;}
	void undo() override 
	{
		Shape* s = v.back();  	
		v.pop_back();			
		delete s;
	}
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
			if ( ! undo_stack.empty() )
			{
				command = undo_stack.top();
				undo_stack.pop();

				if ( command->can_undo() )
				{
					command->undo();
				}

				delete command; // redo 를 지원하려면 여기서 delete 하지말고
								// redo_stack.push(command)
			}
		}
	}
}


// C++ GUI 라이브러리인 QT 에는 "UndoManager" 클래스가 있습니다.

// C# WPF 라이브러리는 "메뉴선택시 실행될 핸들러를 클래스로 만들도록"
// 하고 있습니다.

// 모두 command 패턴을 사용하는 예 입니다.
// java 에서도 아주 널리 사용됩니다.




