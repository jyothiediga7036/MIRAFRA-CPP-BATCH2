#include<iostream>
#include<map>
using  namespace std;

int main()
{
	map<int,string>m={{1,"abcd"},{2,"efgh"},{3,"ijkl"}};

	cout<<"print old method"<<endl;
	for(const auto&[index,value]:m)
		cout<<index<<"->"<<value<<endl;

	cout<<"print new method "<<endl;
	for(const auto& mp:m)
		cout<<mp.first<<"->"<<mp.second<<endl;

	return 0;
}

