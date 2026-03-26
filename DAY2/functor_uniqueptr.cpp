// functor overloaded with paranthases operator
#include<cstdlib>
#include<iostream>
#include<memory>
using namespace std;
struct freedeleter
{
    template<typename t>
    void operator()(t*p)const
    {
        free(p);
        cout<<"memory freed"<<endl;
    }
};
int main()
{
    unique_ptr<int,freedeleter>p{(int *)malloc(sizeof(int))};
    if(!p)
    {
        std::cerr<<"memory allocation failed"<<endl;
        return 1;
    }
    *p=123;
    cout<<*p<<endl;
    return 0;
}