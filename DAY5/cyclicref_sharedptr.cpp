#include<iostream>
#include<memory>
#include<utility>
using namespace std;
class owner;
class car
{
	public:
	shared_ptr<owner>o;
	static int count;
	public:
	car()
	{
		count++;
		cout<<"car is created"<<endl;
	}
	~car()
	{
		count--;
		cout<<"car is destroyed"<<endl;
	}
	void countdata()
	{
		cout<<"count car="<<count<<endl;
	}
};
class owner
{
	public:
	shared_ptr<car>c;
	static int count;
	public:
	owner()
	{
		count++;
		cout<<"owner is created"<<endl;
	}
	~owner()
	{
		count--;
		cout<<"owner is destrode"<<endl;
	}
	void countdata()
	{
		cout<<"count owner="<<count<<endl;
	}
	
};
int car::count=0;
int owner::count=0;
int main()
{
	{
		shared_ptr<car>a=make_shared<car>();
		shared_ptr<owner>b=make_shared<owner>();
	
		a->o=b;
		b->c=a;
		cout<<"in block count"<<endl;
		a->countdata();
		b->countdata();
	}
		cout<<"in after block count'"<<endl;
		cout<<car::count<<endl;
		cout<<owner::count<<endl;

		cout<<"program terminate"<<endl;
}

