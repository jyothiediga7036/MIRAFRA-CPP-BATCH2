#include<iostream>
using namespace std;
class LED
{
	bool b=0;
	public:
	void ON()
	{
		if(!b)
			b=1;

		cout<<"LED ON"<<endl;
	}
	void OFF()
	{
		if(b)
		{
			b=0;
		}
		cout<<"LED off"<<endl;
	}
};
int main()
{
	LED l1;
	l1.ON();
	l1.OFF();
}
