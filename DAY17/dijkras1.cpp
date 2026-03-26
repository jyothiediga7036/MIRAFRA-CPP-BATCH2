#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
void shortestpath(int n,int src,vector<vector<pair<int,int>>>&adj)
{
vector<int>dis(n,INT_MAX);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
dis[src]=0;
p.push({0,src});

while(!p.empty())
{
int weight=p.top().first;
int node=p.top().second;
p.pop();

for(auto edge:adj[node])
{
int new_neighbour=edge.first;
int new_weight=edge.second;
if(dis[new_neighbour]>weight+new_weight)
{
dis[new_neighbour]=weight+new_weight;
p.push({dis[new_neighbour],new_neighbour});
}
}
}

for(int i=0;i<n;i++)
{
if(dis[i]!=INT_MAX)
cout<<"shortest path nodes are "<<dis[i]<<endl;
}
}

int main()
{
int v=6;
vector<vector<pair<int,int>>>adj(v);
adj[0].push_back({2,5});
adj[0].push_back({5,4});
adj[0].push_back({4,2});
adj[2].push_back({1,2});
adj[1].push_back({3,2});
adj[5].push_back({1,3});
adj[5].push_back({3,4});
shortestpath(v,0,adj);
}

