// 방법 #2. strategy 패턴 적용
// => 변하는 것(메모리 할당정책)을 다른 클래스로!!

// 특징 : 컨테이너와 메모리 할당 정책이 분리 된다
// 다른 컨테이너에서도 "MyAllocator" 사용할수 있다.

// 메모리 할당 정책을 모든 컨테이너가 사용가능
// => strategy 패턴의 장점..

// 그런데,, C++ 진영에서는 "가상함수호출의 오버헤드가 싫었다!!!!~"

template<typename T>
struct IAllocator
{
	virtual T* allocate(int sz) = 0;
	virtual void deallocate(T* p , int sz) = 0;

	virtual ~IAllocator(){}
};

template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
	IAllocator<T>* ax;
public:
	vector(int sz, IAllocator<T>* a) : size(sz), ax(a)
	{
		buff = ax->allocate(sz);
		//....
	}
	~vector()
	{
		ax->deallocate(buff, size);
	}
};

// 오직 메모리 할당/해지 정책만 가진 클래스
template<typename T>
class MyAllocator : public IAllocator<T>
{
public:
	T* allocate(int sz) override          
	{ 
		return static_cast<T*>(malloc(sizeof(T)* size));
	}
	void deallocate(T* p, int sz) override 
	{ 
		free(p);
	}
};

int main()
{
	MyAllocator<int> alloc;

	vector<int> v(4, &alloc); // alloc 을 사용해서 메모리 할당/해지해 달라.
}
