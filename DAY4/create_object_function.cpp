#include<iostream>
#include<utility>
using namespace std;
class myclass
{
	int x;
public:
	myclass(int y=0):x(y)
	{
		cout<<"initialization"<<endl;
	}
	myclass(const myclass&t)
	{
		cout<<"copy"<<endl;
		x=t.x;
	}
	myclass(myclass&&t)
	{
		cout<<"move"<<endl;
		x=t.x;
		t.x=0;
	}
	~myclass()
	{
		cout<<"destructor"<<endl;
	}
};
myclass create()
{
	myclass m;
	cout<<"m="<<&m<<endl;
	return m;
}
int main()
{
	myclass x=create();
	cout<<"x="<<&x<<endl;
}
