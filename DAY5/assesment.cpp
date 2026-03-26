#include<iostream>
#include<memory>
#include<utility>
using namespace std;
class sensor
{
	public:
	int n;
	int *temp;
	public:
	sensor(int x=0):n(x)
	{
		cout<<"initialization"<<endl;
		temp=new int[n];
		cout<<"enter element"<<endl;
		for(int i=0;i<n;i++)
			cin>>temp[i];
	}
	void print()
	{
		for(int i=0;i<n;i++)
			cout<<temp[i]<<" ";
		cout<<endl;
	}
	int avg()
	{
		auto s=0;
		for(int i=0;i<n;i++)
		{
			s+=temp[i];
		}
		s=s/n;
		return s;
	}
	~sensor()
	{
		cout<<"object destroyed"<<endl;
		//delete []temp;
	}
};
class deleter
{
	public:
		void operator()(sensor *t)
		{
			cout<<"avg="<<t->avg()<<endl;
			
			delete []t->temp;
			delete t;
		}
};
int main()
{
shared_ptr<sensor>p(new sensor(5),deleter{});
cout<<"count in main="<<p.use_count()<<endl;
shared_ptr<sensor>p1=p;

}

