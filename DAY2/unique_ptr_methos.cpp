#include<iostream>
#include<memory>
using namespace std;
class myclass
{
    int d=10;
    public:
    myclass():d(0)
    {
        cout<<"constructor"<<endl;
    }
    void set()
    {
        cout<<"d="<<d<<endl;
    }
    ~myclass()
    {
        cout<<"destructor"<<endl;
    }
};
int main()
{
    unique_ptr<myclass>p=make_unique<myclass>();
    unique_ptr<myclass>p1=make_unique<myclass>();
    p1.swap(p);
    p1->set();
    
    unique_ptr<myclass>p2=make_unique<myclass>();
    p1.release();
    if(!p1)
    cout<<"p1 is empty"<<endl;
    else
    cout<<" p1 is present"<<endl;
    
    unique_ptr<myclass>p3=make_unique<myclass>();
    p2.reset(new myclass());           // reset with  nullptr
    if(!p2)
    cout<<"p2 is empty"<<endl;
    else
    cout<<" p2 is present"<<endl;
   // unique_ptr<myclass>p4=make_unique<myclass>();
  /* myclass *n=p3.release(new myclass());
   if(!p3)
   cout<<"p3 is now empty"<<endl;
  
  delete n;*/
  unique_ptr<myclass>p4(new myclass());
  myclass*temp=p4.get();
  cout<<*temp<<endl;
  
   //get method is not passed any owenrship of object   
    
}