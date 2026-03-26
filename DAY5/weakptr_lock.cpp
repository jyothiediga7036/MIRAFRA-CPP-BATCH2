#include<bits/stdc++.h>
using namespace std;
class myclass
{
	int x;
	public:
	myclass(int a=0):x(a)
	{
		cout<<"objcet is created"<<endl;
	}
	~myclass()
	{
		cout<<"object destroyed"<<endl;
	}
	void display()
	{
		cout<<"value="<<x<<endl;
	}
};
int main()
{
	shared_ptr<myclass>sp=make_shared<myclass>(45);
	weak_ptr<myclass>wp=make_shared<myclass>();
	cout<<"usecount of before weak="<<wp.use_count()<<endl;
	wp=sp;
	cout<<"usecount of weak="<<wp.use_count()<<endl;
	cout<<"usecount before converting="<<sp.use_count()<<endl;
	if(auto locked=wp.lock())
	{
		locked->display();
		cout<<"usecount after converting="<<sp.use_count()<<endl;
		cout<<"usecount of after weak="<<wp.use_count()<<endl;
	}
	else
		cout<<"oject is nullptr"<<endl;
	cout<<"usecount of main  weak="<<wp.use_count()<<endl;
		cout<<"usecount of  after main shared="<<sp.use_count()<<endl;
}
