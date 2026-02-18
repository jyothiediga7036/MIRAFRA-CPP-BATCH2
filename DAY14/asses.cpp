#include<iostream>
#include<memory>
#include<bits/stdc++.h>
using namespace std;
class sensor
{
	struct node
	{
		int sensor_id;
		float sensor_temp;
		unique_ptr<node>left;
		unique_ptr<node>right;
		node(int x,float y):sensor_id(x),sensor_temp(y){}
	};
	unique_ptr<node>root;
	public:
	void insert_reading(int d,float val)
	{
		insert(root,d,val);
	}
	bool search_sensor(int d)
	{
		return search(root.get(),d);
	}
	void display()
	{
	    inorder(root);
	}
	float findmax()
	{
		if(!root)
			return 0;
		node*cur=root.get();
		while(cur->right)
			cur=cur->right.get();

		return cur->sensor_temp;
	}
	float findmin()
	{
		if(!root)
			return 0;
		node*cur=root.get();
		while(cur->left)
			cur=cur->left.get();

		return cur->sensor_temp;
	}

	private:
	void insert(unique_ptr<node>&n,int d,float val)
	{
		if(!n)
		{
			n=make_unique<node>(d,val);
			return;
		}
		else if(n->sensor_temp > val)
			insert(n->left,d,val);
		else
			insert(n->right,d,val);
	}
    bool search(node* n, int id)
    {
        if (!n)
            return false;

        if (n->sensor_id == id)
            return true;

        return search(n->left.get(), id) ||
               search(n->right.get(), id);
    }
	void inorder(const unique_ptr<node>&root)
	{
	    if(!root)
	    return;
	    
	    inorder(root->left);
	    cout<<"sensor id="<<root->sensor_id<<" "<<"ensor_temp="<<root->sensor_temp<<endl;
	    inorder(root->right);
	}
};
int main()
{
	sensor s;
	s.insert_reading(12,45.6);
	s.insert_reading(34,78.9);
	s.insert_reading(8,67.8);
	s.insert_reading(11,56.3);
	s.insert_reading(23,95.7);
	cout<<"print sensor data"<<endl;
	s.display();
	cout<<"searching node 11 "<<" ";
	cout<<(s.search_sensor(11)?"found" :"not found")<<endl;
	
	cout<<"max tempareture is"<<endl;
	auto x=s.findmax();
	cout<<x<<endl;

cout<<"min temparetur "<<endl;
auto a=s.findmin();
cout<<a<<endl;

}
