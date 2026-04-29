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

// 메뉴 선택시 해야하는 모든 작업들을 수행하는 명령 클래스를 설계

struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// 사각형을 추가하는 명령
class AddRectCommand : public ICommand 
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Rect); } 
	bool can_undo() override { return true; }
	void undo() override 
	{
		if ( v.empty() ) return ;
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};

class AddCircleCommand : public ICommand 
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Circle); } 
	bool can_undo() override { return true; }
	void undo() override 
	{
		if ( v.empty() ) return ;
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

	std::stack<ICommand*> undo_stack; // undo 를 위해 모든 명령을 보관

	ICommand* command = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) 
		{
//			v.push_back(new Rect);	// 작업을 직접 수행하면 undo를 구현하기 어렵습니다

			command = new AddRectCommand(v); // 명령 객체를 만들어서
			command->execute();				 // 명령을 수행
			
			undo_stack.push(command);		// 나중에 필요할때 undo 하기위해 보관
		}
		else if (cmd == 2) 
		{
			command = new AddCircleCommand(v); 
			command->execute();				 			
			undo_stack.push(command);			
		}
		else if (cmd == 9)
		{
			command = new AddDrawCommand(v); 
			command->execute();				 			
			undo_stack.push(command);	
		}
	}
}







