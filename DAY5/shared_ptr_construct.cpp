#include<iostream>
#include<memory>
#include<utility>
using namespace std;
class shared
{
	int x;
	int *p;
	public:
	explicit shared(int a)
	{
		x=a;
		p=new int(1);
		cout<<"initialization"<<endl;
		cout<<"x="<<x<<" "<<"count="<<*p<<endl;
	}
	shared(const shared &t)
	{
		cout<<"copy constructor"<<endl;
		x=t.x;
		p=t.p;
		++(*t.p);
		cout<<"x="<<x<<" "<<"count="<<*p<<endl;

	}
	shared& operator=(shared &t)
	{
		if(this==&t)
			return *this;
		release();
		x=t.x;
		p=t.p;
		++(*p);
		cout<<"copy assignment"<<endl;
		cout<<"x="<<x<<" "<<"count="<<*p<<endl;
		return *this;
	}
	shared(shared &&t)noexcept
	{
		cout<<"move constructor"<<endl;
		x=t.x;
		p=t.p;
		cout<<"x="<<x<<" "<<"count="<<*p<<endl;
		t.x=0;
		t.p=nullptr;
	}
	shared& operator=(shared &&t)noexcept
	{
		if(this==&t)
			return *this;
		release();
		x=t.x;
		p=t.p;

		t.x=0;
		t.p=nullptr;
		cout<<"move assignment"<<endl;
		cout<<"x="<<x<<" "<<"count="<<*p<<endl;
		return *this;
	}
	~shared()
	{
		release();
	}
	void release()
	{
		if(p)
		{
			--(*p);
			cout<<"count="<<*p<<endl;

			if(*p==0)
			{
				cout<<"count="<<*p<<endl;
				delete p;
				cout<<"opject is destroyed"<<endl;
			}
		}
	}
};
int main()
{
	shared s1(10);
	{
		shared s2=s1;  // copy
		shared s3(s2);  // copy 
		shared s5=move(s3);  //move
		s5=move(s2);   // move assing
	}
	cout<<"end of main"<<endl;
}




