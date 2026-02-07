#include<iostream>
using namespace std;
void f(int a)
{
	cout<<a<<endl;
}
void fun(int a,void(*f)(int))
{
	f(a);
}
int main()
{
	fun(10,f);
}
