#include<iostream>
using namespace std;
class mystack
{
	int Size;
	int *arr;
	int capacity;
	public:
	mystack(int x=0):Size(x)
	{
		capacity=20;
		arr=new int[capacity];
		cout<<"object is created"<<endl;
	}
	void push(int x)
	{
		if(Size==capacity)
		{
			cout<<"stack is overflow"<<endl;
			return;
		}
		arr[Size]=x;
		Size++;
	}
	void pop()
	{
		if(Size==0)
		{
			cout<<"stack is empty"<<endl;
			return;
		}
		//	delete arr[size-1];
		Size--;
	}
	void top()
	{
		if(Size==0)
		{
			cout<<"stack is empty"<<endl;
			return;
		}
		cout<<arr[Size-1]<<endl;

	}
int size()
{
return Size;
}
	bool empty()
	{
		if(Size==0)
			return 1;
		else 
			return 0;
	}
	~mystack()
	{
		delete []arr;
	}
};
int main()
{
	mystack s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	cout<<"top element is"<<endl;
	s1.top();
cout<<"size="<<s1.size()<<endl;
	cout<<"the stack elements are"<<endl; 
	while(!s1.empty())
	{
		s1.top();
		s1.pop();
	}

	if(s1.empty())
		cout<<"stack is empty"<<endl;
	else
		cout<<"stack not empty"<<endl;


}

