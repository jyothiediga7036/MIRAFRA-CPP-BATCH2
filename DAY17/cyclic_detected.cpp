#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class detected
{
	int v;
	vector<vector<int>>adj;
	vector<bool>visited;
	vector<bool>restack;
	public:
	detected(int n)
	{
		v=n;
		adj.resize(v);
		visited.resize(v,false);
		restack.resize(v,false);
	}
	void add(int src,int dest)
	{
		adj[src].push_back(dest);
		//adj[dest].push_back(src);
	}
	bool detectcycle()
	{

		int n=v;
		for(int i=0;i<n;i++)
		{
			if(!visited[n])
			{

				if(dfs(i))
					return true;
			}
		}
		return false;
	}
	bool dfs(int n)
	{
		visited[n]=true;
		restack[n]=true;

		for(auto neighbour:adj[n])
		{
			if(!visited[neighbour])
			{
				if(dfs(neighbour))
					return true;
			}
			else if(!restack[neighbour])
				return true;
		}
		restack[n]=false;
		return false;
	}
};
int main()
{
	detected d(3);
	d.add(0,1);
	d.add(1,2);
	d.add(2,0);
	if(d.detectcycle())
		cout<<"cycle is detected"<<endl;
	else
		cout<<"cycle is not detected"<<endl;
}

