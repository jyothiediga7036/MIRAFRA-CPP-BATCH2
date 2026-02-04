#include<bits/stdc++.h>
using namespace std;
class car
{
    int carno;
    int *fuel;
    public:
    car(int x=0,int y=0):carno(x),fuel(new int(y)){}
    car(const car&t)
    {
        cout<<"copy constructor"<<endl;
        carno=t.carno;
        fuel=new int(*t.fuel);
    }
    car& operator=(car &t)
    {
        cout<<"copy assainment constructor"<<endl;
        if(this!=&t)
        {
            cout<<"different memmory location  "<<this<<" "<<&t<<endl;
            delete fuel;
            this->carno=t.carno;
            this->fuel=new int(*t.fuel);
        }
        return *this;
    }
    car(car&&t)noexcept
    {
        cout<<"move constructor"<<endl;
        carno=t.carno;
        fuel=new int(*t.fuel);
        t.carno=0;
        t.fuel=nullptr;
    }
    car& operator=(car&&t)noexcept
    {
        cout<<"move assingment constructor"<<endl;
        if(this!=&t)
        {
            delete fuel;
            this->carno=t.carno;
            this->fuel=new int(*t.fuel);
            t.carno=0;
            t.fuel=nullptr;
        }
        return *this;
    }
    ~car()
    {
        cout<<"destructor"<<endl;
        delete fuel;
    }
    void get()
    {
        if(fuel)
            cout<<"carno="<<carno<<" "<<"fuel="<<*fuel<<endl;
        else
            cout<<"carno="<<carno<<" "<<"fuel=null"<<endl;
    }
};
int main()
{
    car c1(123,78);
    car c2(3456,89);
    c1.get();
    c2.get();
    // copy constructor
    car c3(c2);
    c3.get();
    // copy assingment
    car c4;
    c4=c1;
    c4.get();
    // move constructor
    car o1(5678,80);
    car c5=move(o1);
    c5.get();
    
    // move assingment
    car o2(1982,56);
    car c6;
    c6=move(o2);
    c6.get();
}
