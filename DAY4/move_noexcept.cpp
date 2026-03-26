#include<bits/stdc++.h>
using namespace std;
class GPIO
{
	int pin;
	public:
	GPIO(int x=0):pin(x){
		cout<<"initialization"<<endl;
	}
	GPIO(const GPIO&t)
	{
		cout<<"copy"<<endl;
		pin=t.pin;
		cout<<"pin="<<pin<<endl;
	}
	GPIO(GPIO&&t)noexcept
	//GPIO(GPIO&&t)
	{
		cout<<"move"<<endl;
		pin=t.pin;
		t.pin=-1;
		cout<<"pin="<<pin<<endl;
	}
	~GPIO()
	{
		cout<<"destructor"<<endl;
	}
};
int main()
{
	vector<GPIO>v;
	v.push_back(GPIO(1));
	v.push_back(GPIO(2));
//	v.push_back(GPIO(3));
}
