#include<iostream>
using namespace std;
void (*fp)(int);
void LED(int n)
{
	cout<<"LED on with pin"<<n<<endl;
}
void motor(int n)
{
	cout<<"motor on with on"<<n<<endl;
}
int main()
{
	int pin;
	cout<<"enter the pin"<<endl;
	cin>>pin;
	
	if(pin<25)
	{
		fp=LED;
		fp(pin);
	}
	else
	{
		fp=motor;
		fp(pin);
	}
}





