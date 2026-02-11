#include<iostream>
#include<vector>
#include<list>
#include<array>
#include<algorithm>
using  namespace std;

template<class it>
void print(it first ,it second)
{
while(first!=second)
{
cout<<*first<<" ";
first++;
}
cout<<endl;
}
int main()
{
vector<int>v={1,2,3,4,5};
list<int>l={10,20,30,40,50};
array<char,5>a={'a','b','c','d','e'};
cout<<"vector"<<endl;
print(v.begin(),v.end());
cout<<"list "<<endl;
print(l.begin(),l.end());
cout<<"array"<<endl;
print(a.begin(),a.end());

int p[3]={100,200,300};
cout<<"raw pointer"<<endl;
print(p,p+3);
return 0;
}

