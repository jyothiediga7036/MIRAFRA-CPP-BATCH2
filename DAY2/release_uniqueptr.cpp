#include<bits/stdc++.h>
using namespace std;
int main()
{
    unique_ptr<int>p=make_unique<int>(10);
    cout<<*p<<endl;
    int *raw=p.release();

    if(!p)
    cout<<"memory released"<<endl;
    
    delete raw;
    
    p.reset(new int(20));
    cout<<*p<<endl;
    
}