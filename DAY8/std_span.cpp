#include<iostream>
#include<span>
#include<vector>
using namespace std;
void fun(span<int>s)
{
	for(auto v:s)
	{
		cout<<v<<" ";
	}
	cout<<endl;
}
int main()
{
	vector<int>v={3,1,2,5,6};
	fun(v);
	int arr[]={11,22,33,44,55};
	fun(arr);
}


