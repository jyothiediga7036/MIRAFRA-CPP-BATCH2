#include<iostream>
using namespace std;
int add(int x,int y)
{
	return x+y;
}
int refe(int x)
{
	return x+4;   // rvalue reference
}
void print(int &x)
{
	cout<<"(int &X)="<<x<<endl;
}
void print(const int&x)
{
	cout<<"(const int&x)="<<x<<endl;
}
void print(int &&x)
{
	cout<<"(int&&x)="<<x<<endl;
}
int& transform(int &x)
{
	x*=x;
	return x;
}
int main()
{
	int x=10;
	int &r1=x;  // lvalue reference

//	int &r=10;  //  error cant hold the const values
        const int &r=10;
	const int& r2=r;

	print(x);
	print(3);
	print(100);  // both are called const int& / int&& 

	int &&r3=add(2,3);  // int& r3 is not possible  int r3 /int &&r3 possible 
	print(r3);
	cout<<&x<<endl;
	cout<<&r1<<endl;
	cout<<&r2<<endl;
	cout<<&r3<<endl;
	int &&r4=refe(4);
	cout<<r4<<endl;

	int &r5=transform(x);
	cout<<&r5<<endl;

}
