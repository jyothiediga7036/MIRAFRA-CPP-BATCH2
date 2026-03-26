#include<iostream>
#include<memory>
using namespace std;
class myclass
{
	int x;
	public:
	myclass()
	{
		cout<<"construcor"<<endl;
		x=10;
	//	cout<<"x="<<x<<endl;
	}
	~myclass()
	{
		cout<<"destructor"<<endl;
	}
	void display()
	{
		cout<<"x="<<x<<endl;
	}
};
void useshared(shared_ptr<myclass>p)
{
	p->display();
	cout<<"function call"<<endl;
}
int main()
{
	shared_ptr<myclass>p1=make_shared<myclass>();
	{
		shared_ptr<myclass>p2=p1;
		cout<<"count(p2)="<<p2.use_count()<<endl;
		shared_ptr<myclass>p3(p1);
		cout<<"count="<<p3.use_count()<<endl;
		shared_ptr<myclass>p4=move(p3);
		cout<<"count (p4)="<<p4.use_count()<<endl;
		p4=move(p2);
		cout<<"count (move ass)="<<p4.use_count()<<endl;
		p4.reset();
		cout<<"count reset="<<p1.use_count()<<endl;

	}
	cout<<"count(last)="<<p1.use_count()<<endl;
	useshared(p1);
}
// shared_ptr<myclass>s1; // it will not call the constructor bcoz memory not allocated
// shared_ptrmyclass>s2=make_shared<myclass>();  it will call constructor it saparete memory allocated based on s2 how many objects are created thats use count.
// single object with multiple resoures we can use shared_ptr;
