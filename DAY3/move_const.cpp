// move semantics

#include<bits/stdc++.h>
using namespace std;
class sensor
{
    int *value;
    public:
    	sensor(int x=0);
	sensor( sensor&& t);
	void get()
	{
	cout<<"value="<<*value<<endl;
	}

};
sensor::sensor(int x)
{
	value=new int(x);
}
sensor::sensor(sensor&& t)
{
	cout<<"move constructor"<<endl;
	delete value;
	value=new int(*t.value);
}
int main()
{
	sensor s1(20);
	s1.get();
	sensor s2=move(s1);
	s2.get();
}
