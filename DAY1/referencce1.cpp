#include<iostream>
using namespace std;
int& fun(int &r)
{
	r=r*2;
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
}

