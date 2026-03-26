#include<iostream>
#include<functional>
using namespace std;
int lambda=[](int 
{
	return x+y+z;
}
int main()
{
	auto fun=bind(sum,12,std::placeholders::_1,std::placeholders::_2);
	cout<<"sum="<<fun(23,34)<<endl;
}
