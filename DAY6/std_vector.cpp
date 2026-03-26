#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
	vector<int>v(5,1);
	for(int i=0;i<v.size();i++)
		v[i]=i+5;
	v.push_back(10);
	v.emplace_back(20);
	v.insert(v.begin()+3,100);
	v.emplace(v.begin()+2,25);

	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;

	sort(v.begin(),v.end());
	cout<<"after sorting elements"<<endl;
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
	
	v.pop_back();
	cout<<"capacity="<<v.capacity()<<endl;
	cout<<"size="<<v.size()<<endl;
	if(v.empty())
		cout<<"vector container is emplty"<<endl;
	else
		cout<<"vector container not empty"<<endl;

//	cout<<"reserver="<<v.reserve()<<endl;
	cout<<v.front()<<endl;
	cout<<v.back()<<endl;
	 
	v.resize(4);  // vector size is 4 only 
	
	cout<<v.size()<<endl;

	v.shrink_to_fit();// reallocate the capacity based on elements
	cout<<v.capacity()<<endl;
	

}
