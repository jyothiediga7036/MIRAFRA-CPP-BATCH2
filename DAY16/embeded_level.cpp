#include<iostream>
#include<queue>
#include<memory>
#include<bits/stdc++.h>
using namespace std;
struct node_data
{
	int index;
	string name;
	bool status;
	node_data(int x, string s, bool b = false) : index(x), name(s), status(b) {}
};
class level
{
	struct node
	{
		node_data d;
		unique_ptr<node>left;
		unique_ptr<node>right;
	    node(int x, string s, bool b) : d(x, s, b) {}
	};
	unique_ptr<node>root;
	public:
	void insert(int x,string s,bool st)
	{
		insert_node(root,x,s,st);
	}
	void display()
	{
		level_order(root);
	}
	private:
	void insert_node(unique_ptr<node>&root,int x,string s,bool st)
	{
		if(!root)
		{
			root=make_unique<node>(x,s,st);
			return;
		}
		else if(root->d.index >x)
			insert_node(root->left,x,s,st);
		else
			insert_node(root->right,x,s,st);
	}
	void level_order(unique_ptr<node>&n)
	{
		if(!n)
		{
			cout<<" engin not started"<<endl;
			return;
		}
		queue<node*>q;
		q.push(n.get());
		while(!q.empty())
		{
			node*cur=q.front();
			q.pop();
			if(cur->d.status)
			cout<<cur->d.index<<" "<<cur->d.name<<" "<<" on"<<endl;
			else
				cout<<cur->d.name<<"  not activated  "<<endl;

			if(cur->left)
				q.push(cur->left.get());

			if(cur->right)
				q.push(cur->right.get());
		}
	}

};
int main()
{
	level l;
	l.display();
	l.insert(5,"ECU",true);
	l.insert(3,"dashboard",false);
	l.insert(7,"safety",true);
	l.insert(2,"fuel",true);
	l.insert(4,"speed",true);
	l.insert(6,"airbag",true);
	cout<<"level order traversal"<<endl;
	l.display();
}
