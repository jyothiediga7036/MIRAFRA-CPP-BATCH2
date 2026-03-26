#include<iostream>
#include<vector>
using  namespace std;
class mystack
{
	vector<int>v;
	int s_size;
	public:
	mystack()
	{
		s_size=0;
		cout<<"object is created"<<endl;
	}
	void push(int x)
	{
		v.push_back(x);
		s_size++;
	}
	void pop()
	{
		v.pop_back();
		s_size--;
	}
	int size()
	{
		return s_size;
	}
	int top()
	{
		return v[s_size-1];
	}
	bool empty()
	{
		if(s_size==0)
			return 1;
		else
			return 0;
	}
};
int main()
{
	mystack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	cout<<"top element="<<s1.top()<<endl;
	while(!s1.empty())
	{
		cout<<s1.top()<<" ";
		s1.pop();
	}	
	return 0;
}
