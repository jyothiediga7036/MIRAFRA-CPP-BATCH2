#include<iostream>
#include<memory>
#include<bits/stdc++.h>
using namespace std;
class GPIO
{
	int pin;
	public:
	GPIO(int x=0):pin(x)
	{
		cout<<"initialation"<<endl;
	}
	void fun()
	{
		if(pin)
		cout<<"pin is enable="<<pin<<endl;
		else
			cout<<"pin is disable="<<pin<<endl;
	}
	int getpin()const
	{
		return pin;
	}
};
struct GPIOdeleter
{
	void operator()(GPIO *t)
	{
		cout<<t->getpin()<<endl;
		delete t;
	}	

};
int main()
{
	unique_ptr<GPIO,GPIOdeleter>g(new GPIO(1),GPIOdeleter{});
	g->fun();
	GPIOdeleter d{};
	unique_ptr<GPIO,GPIOdeleter>g1(new GPIO(0),d);
	g1->fun();
}
