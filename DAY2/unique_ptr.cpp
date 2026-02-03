#include<iostream>
#include<memory>  // cppreference unique_ptr;
using namespace std;
class myclass
{
    int d;
    public:
    myclass()
    {
        cout<<"myclass constructor"<<endl;
    }
    ~myclass()
    {
        cout<<"myclass destructor"<<endl;
    }
    void set()const
    {
        cout<<"hello world"<<endl;
    }
};
void fun()
{
    std::unique_ptr<myclass>p=std::make_unique<myclass>();
    p->set();
    std::unique_ptr<myclass>p1=std::make_unique<myclass>();
    p1=move(p);
    if(!p)
    cout<<"p is tranfer ownership"<<endl;   //make_unique work only smart pointers or not
    else
    cout<<"p is present"<<endl;
}
int main()
{
    fun();
}