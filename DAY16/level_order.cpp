#include<iostream>
#include<queue>
#include<memory>
#include<bits/stdc++.h>
using namespace std;
class level
{
	struct node
	{
		int data;
		unique_ptr<node>left;
		unique_ptr<node>right;
		node(int v)
		{
			data=v;
		}
	};
	unique_ptr<node>root;
	public:
	void insert(int d)
	{
		insert_node(root,d);
	}
	void display()
	{
		level_order(root);
	}
	private:
	void insert_node(unique_ptr<node>&root,int d)
	{
		if(!root)
		{
			root=make_unique<node>(d);
			return;
		}
		else if(root->data>d)
			insert_node(root->left,d);
		else
			insert_node(root->right,d);
	}
	void level_order(unique_ptr<node>&n)
	{
		if(!n)
		{
			cout<<"no node are available"<<endl;
			return;
		}
		queue<node*>q;
		q.push(n.get());
		while(!q.empty())
		{
			node*cur=q.front();
			q.pop();
			cout<<cur->data<<" ";
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
	l.insert(50);
	l.insert(30);
	l.insert(70);
	l.insert(20);
	l.insert(40);
	l.insert(60);
	l.insert(80);
	cout<<"level order traversal"<<endl;
	l.display();
}
