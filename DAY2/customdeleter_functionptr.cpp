// customdeleter using function pointers
#include<iostream>
#include<cstdlib>
#include<memory>
using namespace std;
void customdeleter(int *f)
{
    cout<<"delete memory"<<endl;
    free(f);
}
int main()
{
    unique_ptr<int, void(*)(int*)>p{(int *)malloc(sizeof(int)),customdeleter};
    *p=10;
    cout<<*p<<endl;
}// function pointer for custom deleter is not recommended