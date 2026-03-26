#include<bits/stdc++.h>
using namespace std;
class bst
{
	struct node
	{
	int data;
	unique_ptr<node>left;
	unique_ptr<node>right;
	node(int val)
	{
		data=val;
	}
	};
	unique_ptr<node>root;
	public:
	void insert(int d)
	{
		insertval(root,d);
	}
	void inorder()
	{
		inordertravel(root.get());
	}
	bool search(int d)
	{
		return searchfun(root.get(),d);
	}	
	private:
	void insertval(unique_ptr<node>&root,int d)
	{
		if(!root)
		{
			root=make_unique<node>(d);
			return;     
		}
		if(root->data>d)
		{
			insertval(root->left,d);
		}
		else if(root->data<d)
		{
			insertval(root->right,d);
		}
	}
	void inordertravel(node *root)
	{
		if(!root)
		{
			return;
		}
		inordertravel(root->left.get());
		cout<<root->data<<" ";
		inordertravel(root->right.get());
	}
	bool searchfun(const node *n,int d)
	{
	if(!n)
		return false;
	if(n->data==d)
	return true;
	else  if(n->data>d)
	return searchfun(n->left.get(),d);
	else
	return searchfun(n->right.get(),d);
	}
};
int main()
{
	bst t;
	t.insert(20);
	t.insert(15);
	t.insert(5);
	t.insert(8);

	t.inorder();
	string l=t.search(5)?"found":"not found";
	cout<<l<<endl;
}

