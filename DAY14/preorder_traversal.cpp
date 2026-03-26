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
node* insert(node *root,int d)
{
	if(!root)
	{
		return new node(d);     
	}
	if(root->data>d)
	{
		root->left=insert(root->left,d);
	}
	else 
		root->right=insert(root->right,d);
		
		return root;
}
void preorder_recursive(node *root)
{
if(!root)
return;
	cout<<root->data<<" ";
	preorder_recursive(root->left);
	preorder_recursive(root->right);
}
void preorder_iterative(node *root)
{
if(!root)
return;
std::stack<node*>st;
st.push(root);
while(!st.empty())
{
node*cur=st.top();
st.pop();
cout<<cur->data<<" ";
if(cur->right)
st.push(cur->right);
if(cur->left)
st.push(cur->left);
}
}
	
int main()
{
node* root = nullptr;

    int values[] = {50, 30, 20, 40, 70, 60, 80};

    for (int val : values)
        root = insert(root, val);

    std::cout << "Recursive Postorder Traversal:\n";
    preorder_recursive(root);

    std::cout << "\n\nIterative Postorder Traversal:\n";
    preorder_iterative(root);
}
