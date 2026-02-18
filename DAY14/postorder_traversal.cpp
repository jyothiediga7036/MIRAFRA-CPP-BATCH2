#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
int data;
node* left;
node* right;
node(int d):data(d),left(nullptr),right(nullptr){}
};
node* insert(node*root,int d)
{
	if(!root)
	{
		return new node(d);     
	}
	if(root->data>d)
	{
		root->left=insert(root->left,d);
	}
	else if(root->data<d)
	{
		root->right=insert(root->right,d);
	}
	return root;
}
void postorder_recursive(node*root)
{
if(!root)
return;
cout<<root->data<<" ";
postorder_recursive(root->left);
postorder_recursive(root->right);
cout<<root->data<<" ";
}
		
void postorder_iterative(node *root)
{
if(!root)
return;
std::stack<node*>st,st1;
st.push(root);
while(!st.empty())
{
	node*cur=st.top();
	st.pop();
	st1.push(cur);
	if(cur->right)
	st.push(cur->right);
		
	if(cur->left)
	st.push(cur->left);
}
while(!st1.empty())
{
node* c=st1.top();
st1.pop();
cout<<c->data<<" ";
}
}
		

int main()
{
node* root = nullptr;

    int values[] = {50, 30, 20, 40, 70, 60, 80};

    for (int val : values)
        root = insert(root, val);

    std::cout << "Recursive Postorder Traversal:\n";
    postorder_recursive(root);

    std::cout << "\n\nIterative Postorder Traversal:\n";
    postorder_iterative(root);
}
