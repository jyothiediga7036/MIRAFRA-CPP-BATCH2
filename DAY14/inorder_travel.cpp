#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
	node(int d):data(d),left(nullptr),right(nullptr){}
};
void inorder_recursive(node*root)
{
	if(root==nullptr)
		return;
	inorder_recursive(root->left);
	cout<<root->data<<" ";
	inorder_recursive(root->right);
}

void inorder_iterative(node* root)
{
	if(!root)
	return;

	std::stack<node*>st;
	node *cur=root;
	while(cur!=nullptr||!st.empty())
	{
		while(cur!=nullptr)
		{
			st.push(cur);
			cur=cur->left;
		}
	cur=st.top();
	st.pop();		
	cout<<cur->data<<" ";
	cur=cur->right;
	}
}
int main()
{
node* root = new node(50);
root->left = new node(30);
root->right = new node(70);
root->left->left = new node(20);
root->left->right = new node(40);

std::cout << "Inorder Traversal: ";
inorder_recursive(root);
cout<<"inorder stack"<<endl;
inorder_iterative(root);

}
