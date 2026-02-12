#include<iostream>
#include<list>
using  namespace std;
int main()
{
	list<int>l;
	l.push_back(10);
	l.push_front(20);
	l.emplace_front(30);
	l.push_front(40);

	for(auto x:l)
		cout<<x<<" ";
	cout<<endl;

	list<int>l1={1,2,3,4};
	auto it=l.begin();
	advance(it,2);
	l.splice(it,l1);  // move all elements before position
	for(auto x:l)
		cout<<x<<" ";
	cout<<endl;

	for(auto x:l1)   // after transfer the elements list1 has empty
		cout<<x<<" ";
	cout<<endl;


	return 0;
}

