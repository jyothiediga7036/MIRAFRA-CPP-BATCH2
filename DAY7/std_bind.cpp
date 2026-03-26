#include<iostream>
#include<functional>
using namespace std;
int sum(int x,int y,int z)
{
	return x+y+z;
}
int main()
{
	auto fun=bind(sum,12,std::placeholders::_1,std::placeholders::_2);
	cout<<"sum="<<fun(23,34)<<endl;
}
