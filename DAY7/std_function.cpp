#include<iostream>
#include<functional>
using namespace std;
void fun(auto x)
{
	cout<<"inside function="<<x<<endl;
}
int main()
{
	/*function<int(int,int)>f=[](int a,int b)
	{
		return a+b;
	};
	cout<<"sum="<<f(12,34)<<endl;
	*/

	// fuction<auto(auto,auto)>f=[](auto a,auto b)   // in functions generic lambda is not worked
	
	/*auto f=[](auto a,auto b)   //generic lambda
	{
		return a+b;
	};
	cout<<"sum="<<f(12,34)<<endl;
	cout<<"sum="<<f(2.3,5.6)<<endl;
	*/

	/*function<int(int,int)>f=[](int a,int b)
	{
		return a+b;
	};
	cout<<"sum="<<f(12,34)<<endl;
	*/


	// passing lambda to a function
	int t=10;
	auto result=[&](auto x,auto y)
	{
		return x+y+t;
	};
	fun(result(23,67));


	

}

