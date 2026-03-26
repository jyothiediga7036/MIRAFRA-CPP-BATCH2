#include<iostream>
#include<utility>
#include<vector>
using  namespace std;
struct sparse
{
	int index;
	int value;
};

int main()
{
	vector<sparse>p;
	p.push_back({3,4});
	p.push_back({5,2});

	for(auto const[index,value]:p)
	{
		cout<<index<<" "<<value<<endl;
	}
}

