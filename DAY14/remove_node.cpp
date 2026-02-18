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
	void remove_(int d)
	{
		remove_node(root,d);
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
	void remove_node(unique_ptr<node>&n,int d) // why we take reference means  we can modify the original value and in every recursive call the node has been updated
	{
		if(!n)
		return;
		if(d<n->data)
		remove_node(n->left,d); 
		else if(d>n->data)
		remove_node(n->right,d);
		else
		{
			if(!n->left &&!n->right)  // if two childs are not there
			n.reset(); // delete the node 
			else if(!n->left) // only right child is there left =nullptr
			n=move(n->right); // transfer the ownerships 
			else if(!n->right)  //only left child is there right=nulllptr
			n=move(n->left);
			/*else  // to find minnode at right subtree
			{
				//node is uniqueptr
			     node*minnode=n->right.get(); //to creat one min node to getting right child agddress
			     while(minnode->left)
			     minnode=minnode->left.get();
			     
			     n->data=minnode->data;  // copy the data not transfre the data bcoz to avoid memory leaks ,not safer
			     remove_node(n->right,minnode->data);
			}*/
			else  // to find max node at left subtree
			{
			node *maxnode=n->left.get();
			while(maxnode->right)
				maxnode=maxnode->right.get();
				
			n->data=maxnode->data;
			remove_node(n->left,maxnode->data);
			}
		}
		
	}
};
int main()
{
	bst t;
	t.insert(20);
	t.insert(15);
	t.insert(5);
	t.insert(8);
	t.insert(25);
	t.insert(50);

	t.inorder();
	cout<<endl;
	cout<<(t.search(15)?"found":"not found")<<endl;
	t.remove_(20);
	cout<<"after deletingthe node"<<endl;
	t.inorder();
	cout<<endl;	
}

