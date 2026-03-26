#include<iostream>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
	node(int val=0)
	{
		data=val;
		left=nullptr;
		right=nullptr;
	}
	node*insert(node*n,int d)
	{
		if(n==nullptr)
		{
			return new node(d);
		}
		else if(n->data>d)
		{
			n->left=insert(n->left,d);
		}
		else if(n->data<d)
		{
			n->right=insert(n->right,d);
		}
		else
		{
			cout<<"duplicates not allowed"<<endl;
		}
		return n;
	}

};
void inorder(node*root)
{
	if(root==nullptr)
		return;

	inorder(root->left);
	cout<<"data="<<root->data<<" ";
	cout<<"address left="<<&root->left<<" "<<"address right="<<&root->right<<endl;
	inorder(root->right);
}
void deletion(node *root)
{
	if(root==nullptr)
	{
		return;
	}
	deletion(root->left);
	//deletion(root->right);
	cout<<"deleted data="<<root->data<<" "<<"addres="<<&root<<endl;
	deletion(root->right);
	delete root;
}
int main()
{
	node* root=nullptr;
	root=root->insert(root,10);
	root=root->insert(root,5);
	root=root->insert(root,23);
	root=root->insert(root,15);
	root=root->insert(root,40);
	inorder(root);
	deletion(root);
}

