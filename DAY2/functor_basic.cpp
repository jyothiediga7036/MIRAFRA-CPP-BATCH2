#include<bits/stdc++.h>
using namespace std;
class functor
{
    public:
    int operator()(int a,int b)
    {
        cout<<"two parameter functor"<<endl;
        return a>b;
    }
    int operator()(int a,float b,char c)
    {
        cout<<"three parameter functor"<<endl;
        return a+b+c;
    }
};
int main()
{
    functor f;
    cout<<f(4,2)<<endl;
    cout<<f(5,16.6,'A');
}