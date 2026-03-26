#include<iostream>
#include<memory>
using namespace std;
void function_unique(unique_ptr<int>p)  //(unique_ptr<int>&&p) it not transfer the ownership just modify
{
	*p=100;
	cout<<"value in function="<<*p<<endl;
}
int main()
{
	unique_ptr<int>p=make_unique<int>(10);
	cout<<"value in main="<<*p<<endl;
	function_unique(move(p));
	if(p)
		cout<<"pointer is not nullptr"<<endl;
	else
		cout<<"pointer is null"<<endl;
}
