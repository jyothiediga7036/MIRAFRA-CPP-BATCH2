#include<iostream>
using  namespace std;
struct list
{
int data;
struct list *next;
};

int main()
{
list *head=new list{10,nullptr};
list *second=new list{20,nullptr};
list *third=new list{30,nullptr};
head->next=second;
second->next=third;
third->next=nullptr;
list *temp=head;
while(temp)
{
cout<<temp->data<<" ";
temp=temp->next;
}
cout<<endl;

return 0;
}

