#include <iostream>
#include <mutex>

// 동기화!!

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete; 
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;	
	static std::mutex mtx;
public:


	static Cursor& get_instance()
	{
		if ( sinstance == nullptr )
		{
			mtx.lock();
			
			if ( sinstance == nullptr )
			{
				sinstance = new Cursor;

				// 위 한줄은 아래 3가지일을 하게 됩니다
				// 1. Cursor* tmp = sizeof(Cursor) 메모리할당;
				// 2. Cursor() 생성자 호출
				// 3. sinstance = tmp;

				// 위 코드에서 2, 3의 순서를 변경하면
				// tmp 가 없어도 됩니다.
				// => 3번과 1번을 결합
				// 1. sinstance = sizeof(Cursor) 메모리할당;
				// 2. Cursor() 생성자 호출

			}
			
			mtx.unlock();
		}

		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr; 
std::mutex Cursor::mtx;




int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();


}


// godbolt.org

// 구글 "C++11 DCLP" 검색 - 1번째 링크



// cl 컴파일러 필요(visual studio 설치시 설치되는 컴파일러)
// => 사용하시려면 "환경설정이 필요합니다."
// => git 에서 "clsetup.bat" 받으세요

// github.com/codenuri/vddp/DAY3/clsetup.bat


// => DAY3 폴더에 넣고 사용하시면 명령프롬프트창에서
//    clsetup.bat 실행해 주세요


// 시작버튼 누르고
// => "developer command prompt" 검색후 실행
//    하면 바로 cl 사용가능
