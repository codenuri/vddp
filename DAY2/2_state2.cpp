// 1_State1 - 47 page
#include <iostream>

// 1. "item 획득에 따라" 변하는 것과 변하지 않은 것을 구별하세요
// 캐릭터의 상태(멤버데이타) : 변하지 않음
// 캐릭터의 동작(멤버 함수)  : 변함

// 2. 변하는 것 분리 합니다.
// => 실행시간 교체 필요 하다면 "다른 클래스로 분리"

// 변해야 하는 모든 동작 함수를 인터페이스로 설계
struct IState
{
	virtual void do_run() = 0;
	virtual void do_attack() = 0;
	virtual ~IState() {}
};

// 아이템 획득에 따른 동작을 정의 하는 동작 클래스를 각각 제공합니다
class NoItem : public IState 
{
public:
	void do_run()  override   { std::cout << "run" << std::endl; 	}
	void do_attack() override { std::cout << "attack" << std::endl; }
};

class SuperItem : public IState 
{
public:
	void do_run()  override   { std::cout << "fast run" << std::endl; 	}
	void do_attack() override { std::cout << "power attack" << std::endl; }
};

class Character
{
	NoItem noitem;
	SuperItem superitem;

	IState* state = &noitem; // 초기 상태는 아이템이 없는 상태의 동작 사용

	int gold;
	int color;
public:
	void run()    { state->do_run();	}
	void attack() { state->do_attack(); }

	void acquire_item() 
	{
		// item 획득에 따라 멤버 함수를 모두 교체 하는 효과 입니다
		// 객체가 마치 다른 클래스를 사용하는 것처럼 보입니다.
		// => 상태(멤버 데이타)를 유지 하면서 멤버 함수를 교체 한것
		state = &superitem;

		// 타이머 등을 설치 해서 10초쯤 뒤에 다시 아래 코드 실행하도록
		// state = &noitem;
	}
};
int main()
{
	Character c;
	c.run();
	c.attack();

	c.acquire_item();
	c.run();
	c.attack();
}

// strategy 와 state 패턴의 클래스 다이어그램은 동일합니다.
// => 변하는 것을 다른 클래스로 분리 하는 기술

// strategy : 객체가 사용하는 일부 알고리즘의 교체
//			  Edit 의 Validation 알고리즘교체
//		      객체 전체의 동작이 변경되는 것은 아님

// state : 객체 동작 대부분이 교체됨.
//		   다른 클래스를 사용하는 효과!!

// 커피 자판기는 모든 동작이.
// => 돈을 넣지 않았을때와
// => 돈을 넣었을때의 동작이 
// 완전히 다르게 됩니다. - state 패턴!!

