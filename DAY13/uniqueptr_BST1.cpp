#include<bits/stdc++.h>
using namespace std;
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
void inorder(const node*root)
{
	if(!root)
	{
		return;
	}
	inorder(root->left.get());
	cout<<root->data<<" ";
	inorder(root->right.get());
}
unique_ptr<node> insert(unique_ptr<node>&root,int d)
{
	if(!root)
	{
	return make_unique<node>(d);
	}
	else if(root->data>d)
	{
	root->left=insert(root->left,d);
	}
	else if(root->data<d)
	{
	root->right=insert(root->right,d);
	}
	else
	{
	cout<<"duplicates not allowed"<<endl;
	}
	return move(root);	
}
int main()
{
auto root=make_unique<node>(10);
root=insert(root,20);
root=insert(root,15);
root=insert(root,5);
root=insert(root,8);

inorder(root.get());
}

