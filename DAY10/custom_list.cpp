#include<iostream>
using  namespace std;
class list
{
	struct node
	{
		node*prev=nullptr;
		int data;
		node*next=nullptr;
	};
	node*head=nullptr;
	public:
	void push_front(int d)
	{
		node *newnode=new node{nullptr,d,nullptr};
		if(head==nullptr)
		{
			head=newnode;
		}
		else
		{
			head->prev=newnode;
			head=newnode;
		}
	}

	void push_back(int d)
	{
		node *newnode=new node{nullptr,d,nullptr};
		if(head==nullptr)
		{
			head=newnode;
		}
		else
		{
			node*temp=head;
			while(temp->next!=nullptr)
				temp=temp->next;

			temp->next=newnode;
		}
	}
	void insert(node *t,int d)
	{
		node*temp=head;
		while(temp!=t)
			temp=temp->next;

		node*newnode=new node{t,d,t->next};
		if(t->next)
			t->next->prev=newnode;

		t->next=newnode;
	}

	void print()
	{
		node*temp=head;
		cout<<"the elements are"<<endl;
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	void pop_front()
	{
		node*t=head;
		head=head->next;
		head->prev=nullptr;
		delete t;
	}
	void pop_back()
	{
		if(head->next==nullptr)
		{
			delete head;
			head=nullptr;
			return;
		}
		node*temp=head;
		while(temp->next)
			temp=temp->next;

		temp->next->prev=nullptr;
		delete temp;
	}

	void front()
	{
		node*temp=head;
		cout<<temp->data<<endl;
	}
	node*begin()
	{
		return head;
	}
	node*end()
	{
		node*temp=head;
		while(temp->next)
			temp=temp->next;
		return temp->next;
	}
	int size()
	{
		int c=0;
		node*temp=head;
		while(temp)
		{
			c++;
			temp=temp->next;
		}
		return c;
	}
	bool empty()
	{
		if(head==nullptr)
			return true;
		else
			return false;
	}
	/*void erase(node*temp)
	{
	
		if(head==nullptr||temp==nullptr)
			return;
		node*p=head;
		while(p)
		{
			if(head==temp)
			{
				if(p->next==nullptr)
				{
					delete p;
					return;
				}
			
				if(p->prev)
				{
					p->prev->next=p->next;

					if(p->next)
						p->next->prev=p->prev;
		
					delete p;
				}
			}
			p=p->next;
		}
	}*/
	void resize(int x,int d=0)
	{
		int c=0;
		c=size();
		cout<<"size="<<c<<endl;
		if(c<x)
		{
			int n=x-c;
			node*temp=head;
			while(temp->next)
				temp=temp->next;

			while(n)
			{
				node*newnode=new node{temp->next,d,nullptr};
				temp->next=newnode;
				temp=newnode;
				n--;
			}
		}
		else
		{
			int c1=1;
			node*t=head;
			while(c1!=x)
			{
				t=t->next;
				c1++;
			}
			node*temp=t->next;
			t->next=nullptr;
			delete temp;
		}
	}
	void swap(list &t)
	{
		node* n=this->head;
		this->head=t.head;
		t.head=n;

	}
	void remove(int d)
	{
		node*temp=head;
		while(temp!=nullptr)
		{
			if(temp->data==d)
			{
				if(temp==head)
				{
					head=temp->next;
					if(head!=nullptr)
					{
						head->prev=nullptr;
						head=nullptr;
					}
				}
				else
				{
					if(temp->next!=nullptr)
					{
						temp->next->prev=temp->prev;
						temp->prev->next=temp->next;
					}
					else
						temp->prev->next=nullptr;					
				}
				delete temp;
			}
			temp=temp->next;

		}
	}
};
int main()
{
list l1;
l1.push_front(10);
l1.push_back(20);
l1.push_back(30);
auto it=l1.begin();
l1.insert(it,25);
l1.print();
cout<<"size="<<l1.size()<<endl;
//it++;
//l1.erase(it);
l1.print();
cout<<"after increase size"<<endl;
l1.resize(7);
l1.print();
cout<<"size="<<l1.size()<<endl;
cout<<"after decrease size"<<endl;
l1.resize(3);
l1.print();
cout<<"size="<<l1.size()<<endl;

list l2;
l2.push_back(1);
l2.push_front(2);
l2.push_back(3);
//l1.swap(l2);

//l1.print();
//l2.print();
l1.push_back(10);
l1.push_back(40);
l1.push_back(50);
l1.remove(10);
l1.print();

return 0;
}

