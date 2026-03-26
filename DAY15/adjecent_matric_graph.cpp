#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class graphmatrix
{
	int v;
	vector<vector<int>>m;
	public:
	graphmatrix(int vertices)
	{
		v=vertices;
		m.resize(v,vector<int>(v,0)); // 4x4 matrix created initialized to 0
	}
	void addedge(int r,int c)
	{
		m[r][c]=1;
		m[c][r]=1; //undirected graph
	}
	void print()
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
				cout<<m[i][j]<<" ";
			cout<<endl;
		}
	}
};
int main()
{
	graphmatrix m1(4);
	m1.print();
	m1.addedge(0,1);
	m1.addedge(1,2);
	m1.addedge(3,0);
	m1.addedge(1,3);
	m1.print();
}
