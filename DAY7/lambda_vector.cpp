#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int>v={1,2,3,4,5};
	cout<<"vector elements are"<<endl;
	for_each(v.rbegin(),v.rend(),[](auto x)
			{
			cout<<x<<" ";
			});
			cout<<endl;
			
}
