#include<iostream>
using namespace std;
int& fun(const int &r)
{
//	r=r*2; //in constant we can not modify the data 
	//static int l=100;
	int l=100;
	int &x=l;
	return x;

}
int main()
{
	int n=5;
	//int &r=fun(n);
	int r=fun(n);
	cout<<n<<endl;
	cout<<r<<endl;

	int &t=new int(n); //invalid we can not allocate memory for reference variable 

}

