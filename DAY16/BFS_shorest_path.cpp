#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
void bfs(int start,int target,vector<vector<int>>&res)
{
	int v=res.size();
	vector<bool>visited(v,false);
	vector<int>parent(v,-1);

	queue<int>q;
	visited[start]=true;
	q.push(start);

	while(!q.empty())
	{
		int n=q.front();
		q.pop();
		if(target==n)
			break;

		for(int neibour:res[n])
		{
			if(!visited[neibour])
			{
				visited[neibour]=true;
				parent[neibour]=n;
				q.push(neibour);
			}
		}
	}
	auto it=unique(parent.begin(),parent.end());
	parent.erase(it,parent.end());
	int nonvalue=-1;
	auto t1=remove(parent.begin(),parent.end(),nonvalue);
	parent.erase(t1,parent.end());

	cout<<"distance is :"<<parent.size()-1<<endl;

}
int main()
{
	int v=6;
	vector<vector<int>>adj(v);
	adj[0]={1,2};
	adj[1]={0,3,2};
	adj[2]={0,4,1};
	adj[3]={1,4};
	adj[4]={2,3};
	adj[5]={0,2,4};
	cout<<"BFS level order taversal in graph"<<endl;
	bfs(0,4,adj);
}
