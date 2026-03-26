#include<iostream>
#include<memory>
#include<utility>
using namespace std;
class myclass
{
    int data;
    int *p;
    public:
    myclass(int x=0,int y=0):data(x),p(new int(y))
    {
        cout<<"initialization"<<endl;
    }
    myclass(const myclass&t)
    {
        cout<<"copy constructor"<<endl;
        data=t.data;
        p=new int(*t.p);
    }
    myclass(myclass &&t)noexcept
    {
        cout<<"move constructor"<<endl;
        data=t.data;
        p=t.p;
        t.data=0;
        t.p=nullptr;
    }
    void set_data(myclass t)
    {
        cout<<"setby value"<<endl;
        delete p;
        data=t.data;
        p=new int(*t.p);
        cout<<"data="<<data<<" "<<*p<<endl;
    }
    void modify(myclass &t)
    {
        cout<<"modifydata"<<endl;
        data=100;
        *p=25;
        cout<<"data="<<data<<" "<<*p<<endl;
    }
    void readonly(const myclass &t)const
    {
        cout<<"readonly data"<<endl;
        cout<<"data="<<data<<" "<<*p<<endl;
    }
    void transferowner(myclass &&t)
    {
        cout<<"transfer ownership constructor"<<endl;
        delete p;
        data=t.data;
        p=t.p;
        t.data=0;
        t.p=nullptr;
	cout<<"data="<<data<<" "<<*p<<endl;
    }
    ~myclass()
    {
        cout<<"destructor"<<endl;
        delete p;
    }
};
int main()
{
    myclass c1(123,345);
    myclass c2(678,891);
    
    c1.set_data(c2);
    c1.modify(c2);
    c1.readonly(c2);
    c1.transferowner(move(c2));
    
}
