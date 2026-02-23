#include<iostream>
#include<vector>
using namespace std;
void dfs(int n,vector<vector<int>>&adj,vector<bool>&visited)
{
visited[n]=true;
cout<<n<<" ";
for(auto neighbour:adj[n])
{
if(!visited[neighbour])
dfs(neighbour,adj,visited);
}
}
int connected(vector<vector<int>>&adj)
{
int v=adj.size();
vector<bool>visited(v,false);
int c=0;
for(int i=0;i<v;i++)
{
if(!visited[i])
{
cout<<"components "<<c+1<<endl;
dfs(i,adj,visited);
c++;
cout<<endl;
}
}
return c;
}
int main()
{
int v=5;
vector<vector<int>>adj(v);
adj[0].push_back(1);
adj[1].push_back(2);
adj[2].push_back(0);
adj[3].push_back(4);
adj[4].push_back(3);
int c=connected(adj);
cout<<"connected graphs are  "<<c<<endl;
}
