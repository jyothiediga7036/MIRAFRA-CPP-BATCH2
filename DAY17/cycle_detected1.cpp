#include<bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&restack)
{
    visited[node]=true;
    restack[node]=true;
    for(auto neighbour:adj[node])
    {
        if(!visited[neighbour])
        {
            if(dfs(neighbour,adj,visited,restack))
            return true;
        }
        else if(restack[neighbour])
        return true;
    }
    restack[node]=false;
    return false;
}
bool detectecycle(vector<vector<int>>&adj)
{
    int n=adj.size();
    vector<bool>visited(n,false);
    vector<bool>restack(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,adj,visited,restack));
            return true;
        }
    }
    return false;
}
int main()
{
    int v=3;
    vector<vector<int>>adj(v);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    if(detectecycle(adj))
    cout<<"cycle is detected"<<endl;
    else
    cout<<"cycle not detected"<<endl;
}
