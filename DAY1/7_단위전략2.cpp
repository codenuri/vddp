// vector 의 일반 적인 동작 방식은 변하지 않지만
// => 메모리 할당/해지 방법은 교체 가능하게 하고 싶다.

// #1. template method 적용
// => 변하는 것을 가상함수로

template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
		//buff = new T[size];  // 메모리 할당 방법을 직접 정하지 말고
		buff = allocate(size); // 가상함수에 의존
	}
	~vector()
	{
		//delete[] buff;
		deallocate(buff);
	}
	//-------------------------------------
	// 메모리 할당/해지를 책임지는 가상함수
	virtual T* allocate(std::size_t sz) { return new T[sz]; }
	virtual void deallocate(T* p) { delete[] p;  }
};
//-----------------------
// 이제 메모리 할당 방법을 변경하려면
// 1. vector 파생 클래스를 만들어서
// 2. 약속된 2개의 가상함수 allocate/deallocate 를 override 


int main()
{
	vector<int> v(4);
}

