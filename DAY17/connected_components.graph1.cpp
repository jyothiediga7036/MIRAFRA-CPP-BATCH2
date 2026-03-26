#include<iostream>
#include<vector>
using namespace std;
class graph
{
int v;
vector<vector<int>>adj;
public:
graph(int n)
{
v=n;
adj.resize(v);
}
void add(int s,int d)
{
adj[s].push_back(d);
}
void dfs(int n,vector<bool>&visited)
{
visited[n]=true;
cout<<n<<" ";
for(auto neighbour:adj[n])
{
if(!visited[neighbour])
dfs(neighbour,visited);
}
}
int connected()
{
int v=adj.size();
vector<bool>visited(v,false);
int c=0;
for(int i=0;i<v;i++)
{
if(!visited[i])
{
cout<<"components "<<c+1<<endl;
dfs(i,visited);
c++;
cout<<endl;
}
}
return c;
}
};
int main()
{
graph g(5);
g.add(0,1);
g.add(1,2);
g.add(2,0);
g.add(3,4);
g.add(4,3);
int c=g.connected();
cout<<"connected graphs are  "<<c<<endl;
}
