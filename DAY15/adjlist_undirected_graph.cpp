#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;
class graph
{
int v;
map<int,list<int>>adj;
public:
void addadjlist(int v,int u,bool directed=false)
{
adj[u].push_back(v);
if(!directed)
adj[v].push_back(u);
}
void printlist()const
{
for(const auto&x:adj)
{
cout<<"kay="<<x.first<<"->";
for(const auto& val:x.second)
cout<<val<<",";

cout<<"null"<<endl;

}
}
};
int main()
{
graph g1;
g1.addadjlist(1,2);
g1.addadjlist(3,0);
g1.addadjlist(4,2);
g1.addadjlist(0,2);
g1.addadjlist(1,3);
g1.addadjlist(3,4);
g1.printlist();
}

