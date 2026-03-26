#include<iostream>
#include<unordered_map>
using  namespace std;

int main()
{
unordered_map<int,int>mp;
mp[2]=3;
mp[4]=0;

for(int i=1;i<5;i++)
mp[i]=i*3;

for(auto[i,v]:mp)
cout<<i<<"->"<<v<<endl;

return 0;
}

