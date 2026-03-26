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
int main()
{
	auto root=make_unique<node>(10);
	root->left=make_unique<node>(8);
	root->right=make_unique<node>(20);
	root->left->left=make_unique<node>(6);
inorder(root.get());
}
