#include<iostream>
#include<vector>
#include<utility>
using  namespace std;
class sparse
{
	vector<pair<int,int>>p;
	public:
	sparse()
	{
		cout<<"object is created"<<endl;
	}
	~sparse()
	{
		cout<<"object is destroy"<<endl;
	}
	void set(int index,int value)
	{
		if(value!=0)
			p.push_back({index,value});
	}
	void get()
	{
		for(auto const&[i,v]:p)
			cout<<i<<"->"<<v<<endl;
	}
};
int main()
{
	sparse s;
	s.set(4,6);
	s.set(2,5);
	s.get();

	return 0;
}

