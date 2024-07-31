#include <vector>
#include <iostream>

template<typename T>
class MyAllocator 
{
public:
	inline T* allocate(int sz)           
	{ 
		return static_cast<T*>(malloc(sizeof(T)* size));
	}
	inline void deallocate(T* p, int sz)  
	{ 
		free(p);
	}
	// 
};


int main()
{
//	std::vector<int> v; // std::vector<int, std::allocator<T> > v;

	std::vector<int, MyAllocator<int>> v; // 메모리 할당기 교체


	std::cout << "---------------------" << std::endl;

	v.resize(4);

	std::cout << "---------------------" << std::endl;

	v.resize(8);

	std::cout << "---------------------" << std::endl;

}

