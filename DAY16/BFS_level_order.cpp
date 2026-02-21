#include<iostream>
#include<queue>
using namespace std;
void bfs(int start,vector<vector<int>>&res)
{
int v=res.size();
vector<bool>visited(v,false);

queue<int>q;
visited[start]=true;
q.push(start);

while(!q.empty())
{
int n=q.front();
q.pop();
cout<<n<<" ";
for(int neibour:res[n])
{
if(!visited[neibour])
{
visited[neibour]=true;
q.push(neibour);
}
}
}
}
int main()
{
int v=5;
vector<vector<int>>adj(v);
adj[0]={1,2};
adj[1]={0,3};
adj[2]={0,4};
adj[3]={1};
adj[4]={2};
cout<<"BFS level order taversal in graph"<<endl;
bfs(0,adj);
}
