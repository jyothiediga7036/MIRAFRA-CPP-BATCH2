#include<iostream>
using namespace std;
template<class T>
void func(T x)
{
	if constexpr(sizeof(T)==4)
		cout<<"32 bit compiler"<<endl;
	else
		cout<<"non 32 bit compiler"<<endl;
}
int main()
{
	func(32);
	func(23.5);
	func(45.6f);
	func('A');
}
