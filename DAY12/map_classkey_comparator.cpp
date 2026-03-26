#include<iostream>
#include<map>
using namespace std;
class task
{
public:
	string name;
	int id;
	task(const string s=0,int x=0):name(s),id(x){}
};
struct comparator
{
	bool operator()(const task&t1,const task&t2)const
	{
		if(t1.id!=t2.id)
			return t1.id>t2.id;
		return t1.name>t1.name;
	}
};
int main()
{
	map<task,int,comparator>p;
	p[task("ijkl",3)]=100;
	p[task("tuvw",3)]=200;
	p[task("wxyz",5)]=25;
	p[task("abcd",7)]=50;

	for(const auto x:p)
		cout<<x.first.name<<" "<<x.first.id<<" "<<x.second<<endl;
}
