#include<iostream>
using namespace std;
void fun()
{
}
int i;
int main()
{
	int n;
	static int c;
	int j=10;
	const float f=3.14;
	int *p=new int(10);
	cout<<"int="<<&n<<endl;
	cout<<"static="<<&c<<endl;
	cout<<"const="<<&f<<endl;
	cout<<"heap="<<&p<<endl;
	cout<<"global="<<&i<<endl;
	cout<<"initial="<<&j<<endl;
	cout<<"func="<<&fun<<endl;
}
