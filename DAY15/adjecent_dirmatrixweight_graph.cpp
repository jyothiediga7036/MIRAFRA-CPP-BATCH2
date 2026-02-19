#include<iostream>
#include<bits/stdc++.h>
#include<limits>// INF header file c++20
using namespace std;
template<class T>
class directed_weight_graph
{
	int v;
	T INF;   //its a standerd character sequence ,infinite
	vector<vector<T>>m;
	public:
	directed_weight_graph(int vertices)
	{
		v=vertices;
		INF=numeric_limits<T>::max();
		m.resize(v,vector<T>(v,INF)); // 4x4 matrix created initialized to 0
	}
	void addedge(T r,T c,T w)
	{
		if(r>=0&&r<v && c>=0&& c<v)
		{
			m[r][c]=w; //directed graph
		}
		else
		throw out_of_range("directed_weighted_graph");
	}
	void print()const
	{
		for(auto row:m)
		{
		for(auto val:row)
		{
		if(val==INF)
		cout<<std::setw(6)<<"";
		else
		cout<<std::setw(6)<<val<<"~";
		}
		cout<<endl;
		}
	}
};
int main()
{
	directed_weight_graph<int> m1(4);
cout<<"no weight "<<endl;
	m1.print();
	m1.addedge(0,1,3);
	m1.addedge(1,2,4);
	m1.addedge(3,0,2);
	m1.addedge(1,3,5);
cout<<"after adding weight"<<endl;
	m1.print();
}
