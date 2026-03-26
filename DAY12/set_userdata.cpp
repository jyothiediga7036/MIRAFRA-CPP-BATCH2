#include<iostream>
#include<set>
using namespace std;
struct process
{
	int priority;
	string name;
	int id;
	process(int x=0,string s=0,int y=0):priority(x),name(s),id(y){}
friend ostream&  operator<<(ostream&out,const process &t)
{
	out<<t.priority<<" "<<t.name<<" "<<t.id<<endl;
	return out;
}
};
struct comparision
{
	bool operator()(const process&t1,const process&t2)const
	{
		cout<<"comparision called"<<endl;
		if(t1.priority==t2.priority)
		return t1.id<t2.id;
		return t1.priority<t2.priority;
	}
};
int main()
{
	set<process,comparision>p;
	p.insert({12,"abcd",5});
	p.insert({9,"ijkl",2});
	p.insert({15,"wxyz",7});
	p.insert({15,"mnop",1});

	for(const auto& x:p)
	{
	cout<<x<<endl;
	}
}
