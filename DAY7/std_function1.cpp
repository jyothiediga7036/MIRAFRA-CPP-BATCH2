#include<iostream>
#include<functional>
using namespace std;
void (*fp)(int,int);
void sum(int a,int b)
{
	cout<<a+b<<endl;
}
int main()
{
	/*function<int(int)>f=[](int v)
	{
		return v;
	};
	cout<<f(5)<<endl;*/
	
	fp=sum;
	function<void(int,int)>f=fp;
	f(4,5);



}

