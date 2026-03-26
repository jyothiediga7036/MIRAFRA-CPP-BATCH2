#include<iostream>
using  namespace std;
class forwardlist
{
public:
	int data;
	forwardlist *next;
	forwardlist *head;
	void push_front(int d)
	{
		forwardlist*node=new forwardlist;
		node->data=d;
		node->next=head;
		head=node;
	}
	void push_back(int d)
	{
		forwardlist*node=new forwardlist;
		node->data=d;
		node->next=nullptr;
		if(head==nullptr)
		{
			head=node;
		}
		else
		{
			forwardlist*temp=head;
			while(temp->next!=nullptr)
				temp=temp->next;

			temp->next=node;
		}
	}
	void insert_after(forwardlist*node,int d)
	{
		forwardlist *t=head;
		while(t!=node &&t!=nullptr)
		{
			t=t->next;
		}
		if(t==nullptr)
			return;
		forwardlist* p=new forwardlist{d,t->next};
		t->next=p;
	}
	void print()
	{
		forwardlist*temp=head;
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	void pop_front()
	{
		if(head==nullptr)
			return;
		forwardlist *temp=head;
		head=temp->next;
		delete temp;
	}
	void clear()
	{
		forwardlist*temp=head;
		while(temp->next!=nullptr)
		{

			head=temp->next;
			delete temp;
			temp=head;
		}
		head=nullptr;
	}
	int front()
	{
		return head->data;
	}
	int back()
	{
		forwardlist*temp=head;
		while(temp->next!=nullptr)
			temp=temp->next;

		return temp->data;
	}
	void erase_after(forwardlist*node,int x)
	{
		int i=1;
		while(i!=x&& node->next!=nullptr)
		{
			node=node->next;
			i++;
		}
		forwardlist *last=node->next;
		node->next=node->next->next;
		delete last;

	}
	forwardlist* begin()
	{
		return head;
	}
	forwardlist* end()
	{
		forwardlist*temp=head;
		while(temp->next!=nullptr)
			temp=temp->next;

		return temp;
	}
	bool empty()
	{
		if(head==nullptr)
			return true;
		else
			return false;
	}

};

int main()
{
	forwardlist f;
	f.push_back(10);
	f.push_front(20);
	f.push_back(30);
	auto i=f.begin();
	f.insert_after(i,25);
	f.print();
	//f.pop_front();
	//f.print();
	cout<<f.front()<<endl;
	cout<<f.back()<<endl;
	auto it=f.begin();
	f.erase_after(it,3);
	cout<<"after erase"<<endl;
	f.print();
	f.clear();
	if(f.empty())
		cout<<"forwardlist is empty"<<endl;
	else
		cout<<"forwardlist is not empty"<<endl;
	//if(it!=f.end())
	//cout<<it->data<<endl;


	return 0;
}

