#include<iostream>
using namespace std;
class LED
{
	bool b=0;
	public:
		void display()
		{
			if(b)
			{
				cout<<"LED ON"<<endl;
				b=0;
			}
			else
			{
				cout<<"LED OFF"<<endl;
				b=1;
			}
		}
};
int main()
{
	LED l1;
	l1.display();
	l1.display();
	l1.display();
}

