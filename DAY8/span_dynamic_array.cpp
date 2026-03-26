#include<iostream>
#include<span>
#include<vector>
using namespace std;

void fun(span<int>s)
{
    for(auto &x:s)
        x=x*x;
}
int main()
{
    int size=5;
     int*p=new int[size]{1,2,3,4,5};
     fun(span<int>(p,size));
     
     for(int i=0;i<size;i++)
        cout<<p[i]<<" ";
        cout<<endl;
     delete []p;
}
