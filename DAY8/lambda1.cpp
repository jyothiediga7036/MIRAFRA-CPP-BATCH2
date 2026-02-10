#include<iostream>
#include<functional>
using namespace std;
void fun()
{
int x=10;
}
int main()
{
//static int x=10;   // error
	function<int()>f;
	{
		//int x=10;
		f=[&x]()
		{
			return x;
		};
	}
	cout<<f()<<endl;
}
