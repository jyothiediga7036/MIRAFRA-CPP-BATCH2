#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
void shortestpath(int n,int src,vector<vector<pair<int,int>>>adj)
{
vector<int>dis(n,INT_MAX);
dis[src]=0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
p.push({0,src});
while(!p.empty())
{
int d=p.top().first;
int node=p.top().second;
p.pop();
for(auto&ed:adj[node])
{
int v=ed.first;
int weight=ed.second;
if(dis[v]>d+weight)
{
dis[v]=d+weight;
p.push({dis[v],v});
}
}
}
for(int i=0;i<n;i++)
{
if(dis[i]!=INT_MAX)
cout<<"shortest path to visited nodes"<<i<<" -> "<<dis[i]<<endl;
}
}

int main()
{
    int n=6;
vector<vector<pair<int,int>>>adj(n);
adj[0].push_back({1,4});
adj[0].push_back({2,1});
adj[2].push_back({1,2});
adj[1].push_back({3,1});
adj[2].push_back({3,5});
adj[3].push_back({4,3});

shortestpath(n,0,adj);
}
