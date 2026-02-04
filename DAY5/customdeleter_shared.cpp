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
	~GPIO()
	{
		cout<<"destructor"<<endl;
	}
};
struct GPIOdeleter
{
	void operator()(GPIO *t)
	{
		cout<<t->getpin()<<endl;
		cout<<"custom deleter"<<endl;
		delete t;
	}	

};
void moduleA(shared_ptr<GPIO>t)
{

	cout<<"module a count="<<t.use_count()<<endl;
	cout<<t->getpin()<<endl;
}
void moduleB(shared_ptr<GPIO>t)
{

	cout<<"module b  count="<<t.use_count()<<endl;
	cout<<t->getpin()<<endl;
}

int main()
{
	shared_ptr<GPIO>g(new GPIO(12),GPIOdeleter{});
	
	moduleA(g);
	cout<<"main count="<<g.use_count()<<endl;
	moduleB(g);
	cout<<"main count="<<g.use_count()<<endl;

}
