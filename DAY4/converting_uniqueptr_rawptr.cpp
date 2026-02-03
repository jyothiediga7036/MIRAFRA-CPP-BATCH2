#include<bits/stdc++.h>
using namespace std;
void fun(int*p)
{
	*p=100;
	cout<<"inside function value="<<*p<<endl;
	cout<<"address="<<p<<endl;
}
int main()
{
	unique_ptr<int>p=make_unique<int>(32);
	cout<<"int main value="<<*p<<endl;
	cout<<"address="<<p.get()<<endl;
	fun(p.get()); // convertion to raw pointer
	cout<<"in main after fun value="<<*p<<endl;
	cout<<"address="<<p.get()<<endl;

	if(!p)
		cout<<"unique pointer is null after function"<<endl;
	else
		cout<<"unique pointer still hold the value"<<endl;

}
