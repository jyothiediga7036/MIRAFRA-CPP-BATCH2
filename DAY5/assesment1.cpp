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
	sensor(int x=0,int*p=nullptr)
	{
		cout<<"initialization"<<endl;
		temp=p;
		n=x;
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
	int n;
	cout<<"enter the element"<<endl;
	cin>>n;
	int *p=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
shared_ptr<sensor>q(new sensor(n,p),deleter{});
cout<<"count in main="<<q.use_count()<<endl;

}

