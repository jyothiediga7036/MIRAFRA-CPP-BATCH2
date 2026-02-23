#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void shortestpath(int src)
{
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
vector<int>dis(v,INT_MAX);
dis[src]=0;
p.push({0,src});
while(!p.empty())
{
int d=p.top().first;
int node=p.top().second;
p.pop();

for(auro ed:adj[node])
{
int neighbour=ed.first;
int weight=ed.second;
if(dis[neighbour]>
int main()
{
add(0,1,4);
add(0,2,1);
add(1,2,2);
add(1,3,1);
add(2,3,5);
add(3,4,3);
}
