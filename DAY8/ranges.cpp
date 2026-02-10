#include<iostream>
#include<ranges>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int>v={1,4,2,5,7,3,8,0,9};

	std::ranges::sort(v);

	for(auto x:v)
		cout<<x<<" ";
	cout<<endl;

	// finding element
	auto it=ranges::find(v,5);
	if(it!=v.end())
		cout<<distance(v.begin(),it)<<endl;   // from begin to how much distance is there to finding element
	
	vector<int>v1(v.size());

	ranges::copy(v,v1.begin());
	for(auto x:v1)
		cout<<x<<" ";
	cout<<endl;

	
}
