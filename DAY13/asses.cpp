#include<iostream>
#include<memory>
using  namespace std;
struct data
{
	float rating;
	string car_name;
	int fuel;
	data(float f,string s,int x):rating(f),car_name(s),fuel(x){}
};
class car
{
	struct node
	{
		data d;
		node *left;
		node*right;
		node(data v):d(v),left(nullptr),right(nullptr){}
	};
	node *root=nullptr;
	public:
	void insert(const data&d)
	{
		insertnode(root,d);
	}
	void inorder()const
	{
		inorderdata(root);
	}
	bool search(string p)
	{
	return searchcar(root,p);
	}
	private:
	void insertnode(node*&n,const data&val) // reference to pointer has Modify the actual pointer
	{
		if(n==nullptr)
		{
			n=new node(val);
			return;
		}
		if(n->d.rating>val.rating)
		{
			insertnode(n->left,val);
		}
		else 
			insertnode(n->right,val);
	}
	void inorderdata(node*n)const
	{
		if(n==nullptr)
			return;

		inorderdata(n->left);
		cout<<n->d.rating<<" "<<n->d.car_name<<" "<<n->d.fuel<<endl;
		inorderdata(n->right);
	}
	bool searchcar(node *&n,string p)
	{
		if(n==nullptr)
		return false;
		
		if(n->d.car_name==p)
		return true;
		else if(n->d.car_name>p)
		return searchcar(n->left,p);
		else
		return searchcar(n->right,p);
	}
};
int main()
{
	car c1;
	c1.insert(data(7,"toyota",78));
	c1.insert(data(5,"suzuki",67));
	c1.insert(data(9,"thar",89));
	c1.insert(data(4,"honda",67));
	c1.insert(data(8,"benz",80));

	cout<<"car details"<<endl;
	c1.inorder();
	
	string s;
	cout<<"ask customer which car they want"<<endl;
	cin>>s;
	cout<<(c1.search(s)?"found":"not fount");
	
}

