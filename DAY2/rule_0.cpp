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

cout<<"room1="<<endl;
room1.print();
cout<<"room2="<<endl;
room2.print();

room1=room2;
cout<<"after assing="<<endl;
room1.print();
car room3=room1;
room3.set(1,999);  //after copying we can change the value also 
cout<<"room3"<<endl;
room3.print();

}