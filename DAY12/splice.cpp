#include<iostream>
#include<list>
using  namespace std;

int main()
{
list<int>l1={1,2,3,4};
list<int>l2={10,20,30};
auto it=l2.begin();
//l1.splice(l1.begin(),l2);  // total l2 elements are move to l1
 l1.splice(l1.begin(),l2,it);   // move only first element to l1 
//l1.splice(l1.begin(),l2,l2.begin(),l2.end());  //move range of elements to l1;


cout<<"l1 elements"<<endl;
for(auto x:l1)
cout<<x<<" ";
cout<<endl;

cout<<"l2 elements"<<endl;
for(auto x:l2)
cout<<x<<" ";
cout<<endl;


return 0;
}

