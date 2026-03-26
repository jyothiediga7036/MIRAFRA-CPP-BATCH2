#include<iostream>
#include<ranges>
#include<vector>
using namespace std;
void print(span<int>s)
{
    for(auto x:s)
    {
        x=x*x;
    }
}
int main()
{
    vector<int>v={2,3,1,5,6,8};
    auto even=v|std::views::filter([](int x)
    {
        return x%2==0;   
    });
    
    for(auto i:even)
    cout<<i<<" ";
    cout<<endl;
    
    print(even);
    
    for(auto i:even)
    cout<<i<<" ";
    cout<<endl;
    
    auto square=v|std::views::transform([](int x)
    {
        return x*x;
    });
    for(auto i:square)
    cout<<i<<" ";
    cout<<endl;
     print(transform);
    
    for(auto i:v)
    cout<<i<<" ";
    cout<<endl;
    
}
