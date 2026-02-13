#include<iostream>
#include<stack>
using namespace std;
class mystack
{
	public:
		int p_id;
		string p_name;
		bool running_state;
		friend ostream& operator<<(ostream&,mystack&p);

mystack(const mystack &t)
{
p_id=t.p_id;
p_name=t.p_name;
running_state=t.running_state;
}
};
ostream& operator<<(ostream&out ,mystack&p)
{
	out<<p.p_id<<" "<<p.p_name<<" "<<p.running_state<<endl;
	return out;
}


int main()
{
	stack<mystack>s;
	s.push({10,"one",true});
	s.push({12,"two",false});
	cout<<s.top()<<endl;

	if(s.empty())
		cout<<"stack is empty"<<endl;
	else
		cout<<"stack not empty"<<endl;

	s.pop();
	cout<<s.top()<<endl;
stack<mystack>s1=s;

cout<<s1.top()<<endl;

}
