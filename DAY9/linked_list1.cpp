#include<iostream>
using  namespace std;
struct node
{
int data;
node *next;
};
void insert_front(int d,node* t)
{
node*newnode=new node(d);

}
void insert_back(int d)
{
node*newnode=new node(d);
if(head==nullptr)
{
head=newnode;
return;
}
node *t=head;
while(t->next!=nullptr)
t=t->next;

t->next=newnode;
newnode->next=nullptr;
}
void delete_all(node *head)
{
if(head==nullptr)
return;
node *temp=head;
while(temp)
{
head=temp->next;
delete temp;
temp=head;
}
}
void delete_first(node*head)
{
if(head==nullptr)
return;

node *temp=head;
head=temp->next;
delete temp;
}
int main()
{



return 0;
}

