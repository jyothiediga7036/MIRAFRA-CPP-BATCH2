#include<iostream>
using namespace std;
int main()
{
	int a=10;
	int&r=a;
	int b=20;
	int *p=&b;
	int *&r1=p;
	cout<<&a<<endl;
	cout<<&r<<endl;
	cout<<&p<<endl;
	cout<<&r1<<endl;
	int x=5;
	r=x;
	cout<<r<<endl;
//	int &r2; //invalid
	const int *p2;
	const int y=20;
	p2=&y;
	const int &r3=a;
	cout<<&r3<<endl;

	// int data to const reference is possible 
	// const int data to int reference is not possible 
	// const data to const reference is possible 

	
}
