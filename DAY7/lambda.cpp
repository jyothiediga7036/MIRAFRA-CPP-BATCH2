#include<iostream>
using namespace std;
int main()
{
	 int temp=10;
	string  motor_name;
	bool f=false;
//	auto motor=[&](int val) //all local variables in reference ,but const local variable can not modify 
//	auto motor=[=](int val)  // all  local variables in call by value
//	auto motor=[=](int val)mutable  // we can change but it not effect on original data , but const local variable can not modify 
//	auto motor=[](int val)   // without capture any value we can not modify
//	auto motor=[&motor_name,temp](int val) //some are call by value ,some are call by reference 
	auto motor=[&](int val) // throwing an exception    
	{
		if(val>25)
			throw "motor";
		temp=temp+10;
		motor_name="synchronous";
		cout<<"motor name="<<motor_name<<endl;
		if(f)
		{
			cout<<"motor is on"<<endl;
				f=0;
		}else
		{
			cout<<"motor is off"<<endl;
			f=1;
		}
	};
	try
	{
		motor(50);
	}
	catch(const char*p)
	{
		cout<<"exception:"<<p<<endl;
	}
			cout<<"temp="<<temp<<endl;
		cout<<"motor name="<<motor_name<<endl;
		cout<<"motor state="<<f<<endl;
}

		
