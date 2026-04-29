#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	sp<ICalc> calc1 = load_proxy(); 
	sp<ICalc> calc2 = calc1;
	
	int n1 = calc1->Add(10, 20);
	int n2 = calc2->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}







