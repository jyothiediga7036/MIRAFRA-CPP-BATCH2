#include<iostream>
#include<memory>
using namespace std;
class  CAN
{
	int pin;
	public:
	CAN()
	{
		cout<<"constructor"<<endl;
		cout<<pin<<endl;
	}
};
int main()
{
	CAN c1{};// error bcoz parameter only there default can be deleted

CAN c;  //it  call parameter constructor
//	   CAN c();    //error
//
}

// without data member how it will work
