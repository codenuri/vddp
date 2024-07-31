// 1_State1 - 47 page
#include <iostream>

class Character
{
	int gold;
	int color;
public:
	void run()    
	{ 
		// 아래 처럼 만들면
		// => 모든 동작함수에 제어문 필요
		// => 새로운 아이템 나오면 모든 동작함수를 변경(제어문 추가)해야 합니다.
		// => OCP 만족 안함.
		if ( item 획득 안한 경우)
			std::cout << "run" << std::endl; 
		else 
			std::cout << "fast run" << std::endl; 
	}
	void attack() { std::cout << "attack" << std::endl; }

	void acquire_item() 
	{
		// ??
	}
};
int main()
{
	Character c;
	c.run();
	c.attack();

	// 게임의 캐릭터는 아이템 획득시 모든 동작이 바뀐다고 가정해 봅시다
	// 어떻게 코드를 만드는 것이 최선 일까요 ?
	c.acquire_item();
	c.run();
	c.attack();
}



