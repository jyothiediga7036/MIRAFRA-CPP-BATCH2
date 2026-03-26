#include<iostream>
#include<queue>
using namespace std;
struct process
{
	int priority;
	string name;
	int brust_time;
	process(int x=0,string s=0,int y=0):priority(x),name(s),brust_time(y){}
friend ostream&  operator<<(ostream&out,const process &t)
{
	out<<t.priority<<" "<<t.name<<" "<<t.brust_time<<endl;
	return out;
}
};
struct comparision
{
	bool operator()(const process&t1,const process&t2)const
	{
		return t1.brust_time<t2.brust_time;
	}
};
int main()
{
	priority_queue<process,vector<process>,comparision>p;
	p.push({12,"abcd",5});
	p.push({9,"ijkl",2});
	p.push({15,"wxyz",7});

	while(!p.empty())
	{
		cout<<p.top()<<" ";
		p.pop();
}
}
