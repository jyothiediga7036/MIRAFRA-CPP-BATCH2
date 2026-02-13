#include<iostream>
using  namespace std;
class queue
{
	struct node
	{
		node*prev=nullptr;
		int data;
		node*next=nullptr;
	};
	node*head=nullptr;
	public:
	void push(int d)
	{
		node *newnode=new node{nullptr,d,nullptr};
		if(head==nullptr)
		{
			head=newnode;
		}
		else
		{
			node*t=head;
			while(t->next!=nullptr)
				t=t->next;

			t->next=newnode;
		}
	}
	void pop()
	{
		if(head==nullptr)
			return;
		node*t=head;
		head=head->next;
		if(head)
			head->prev=nullptr;
		delete t;

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
	int front()
	{
		if(head!=nullptr)
			return head->data;
		else
		{
			cout<<"queue is empty"<<endl;
			return 0;
		}
	}
	int back()
	{
		if(head==nullptr)
			return 0;
		node *t=head;
		while(t->next!=nullptr)
			t=t->next;

		return t->data;
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
	queue q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	cout<<"size="<<q.size()<<endl;
	cout<<q.front()<<endl;
	q.pop();
	cout<<"back element="<<q.back()<<endl;

	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}

