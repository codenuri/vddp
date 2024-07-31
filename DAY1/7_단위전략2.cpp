// 방법 #1. template method 사용
// => 변해야 하는 것(메모리 할당/해지) 를 가상함수로 분리

// 특징 : 메모리 할당 해지 방법이 "MyVector"의 소유가 된다.
//       std::list, set 등 도 메모리할당 방법을 변경하려면
//       파생클래스를 만들어서 다시 메모리 할당 방법을 제공해야 한다.

template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
		buff = allocate(size);
		//....
	}
	~vector()
	{
		dellocate(buff, size);
		//....
	}
	// vector 내부의 모든 코드에서는 메모리할당/해지가 필요할때 마다
	// 아래 2개 가상함수에 의존해야 합니다.
	virtual T* allocate(int sz)          { return new T[sz]; }
	virtual void dellocate(T* p, int sz) { delete[] p; }
};

// 의도 : 메모리 할당 방식을 변경하려면 파생 클래스를 만들어서 약속된
//       가상함수 override 

template<typename T>
class MyVector : public vector<T>
{
public:
	MyVector(int sz) : vector<T>(sz){}

	T* allocate(int sz) override          
	{ 
		return static_cast<T*>(malloc(sizeof(T)* size));
	}
	void dellocate(T* p, int sz) override 
	{ 
		free(p);
	}
};
int main()
{
	MyVector<int> v(4);
}
