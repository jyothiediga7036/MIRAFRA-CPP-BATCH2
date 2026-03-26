#include<iostream>
#include<vector>
#include<climits>
using namespace std;
bool dfs(int node ,int parent,vector<vector<int>>&adj,vector<bool>&visited)
{
	visited[node]=true;
	for(auto neighbour:adj[node])
	{
		if(!visited[neighbour])
		{
			if(dfs(neighbour,node,adj,visited))
				return true;
		}
		else if(neighbour!=parent)
			return true;
	}
	return false;
}

int main()
{
	int v=4;
	vector<vector<int>>adj(v);
	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(2);
	adj[3].push_back(0);
	adj[0].push_back(3);

	vector<bool>visited(v,false);

	bool c=false;
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			if(dfs(i,-1,adj,visited))
			{
				c=true;
				break;
			}
		}
	}

	if(c)
		cout<<"cycle is detected"<<endl;
	else
		cout<<"cycy;e is not detectd"<<endl;
}

