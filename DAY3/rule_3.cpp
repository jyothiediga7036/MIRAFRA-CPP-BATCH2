#include<bits/stdc++.h>
using namespace std;
class copydata
{
    int fuel;
    int *carno;
    public:
    copydata(int x=0,int y=0):fuel(x),carno(new int(y))
    {
        cout<<"constructor"<<endl;
    }
    copydata(const copydata& t):fuel(t.fuel)
    {
        carno=new int(*t.carno);
        cout<<"deep copy constructor"<<endl;
    }
    copydata& operator=(const copydata &t)
    {
        if(this!=&t)
        {
            cout<<"both are  different location"<<endl;
            this->fuel=t.fuel;
            delete(this->carno);
        
        	this->carno=new int (*t.carno);
	}
        return *this;
    }
    void get()
    {
        cout<<"fuel="<<fuel<<" "<<"carno="<<carno<<endl;
    }
};
int main()
{
    copydata c1(70,3240);
    copydata c2;
    c1.get();
    c2=c1;
c2.get();        
}
