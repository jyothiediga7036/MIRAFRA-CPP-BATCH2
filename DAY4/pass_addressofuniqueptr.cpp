#include<iostream>
#include<memory>
using namespace std;
void function_unique(unique_ptr<int>*p)  //(unique_ptr<int>&&p) it not transfer the ownership just modify
{
	*p=make_unique<int>(100);
	//**p=100;
	cout<<"value in function="<<**p<<endl;
	cout<<"addrss= "<<p<<endl;   //stack
	cout<<"address in fun="<<(*p).get()<<endl; //heap
//	cout<<"address in fun="<<((*p).get()).get()<<endl; // error
}
int main()
{
	unique_ptr<int>p=make_unique<int>(10);  //stack
	cout<<"value in main="<<*p<<endl;
	cout<<"address="<<&p<<endl;  //stack 
	cout<<"address="<<p.get()<<endl;  // heap
	function_unique(&p);
	if(p)
		cout<<"pointer is not nullptr"<<endl;
	else
		cout<<"pointer is null"<<endl;
}
