//rule of 0
#include<bits/stdc++.h>
using namespace std;
class car
{
	vector<int>v;
public:
	explicit car(int c):v(c,0){}

	void set(int x,int y)
	{
			if(x<v.size())
			v[x]=y;
	}
	void print()const
	{
		cout<<"total cars="<<v.size()<<endl;
		for(int i=0;i<v.size();i++)
			cout<<"car="<<(i+1)<<" "<<"no="<<v[i]<<endl;
	}
};
int main()
{
car room1(2);
room1.set(0,120);
room1.set(1,240);

car room2(3);
room2.set(0,123);
room2.set(1,234);
room2.set(2,3456);

room1.print();
room2.print();
}
