#include<iostream>
#include<ranges>
#include<vector>
#include<map>
using namespace std;
int main()
{
    vector<int>v={1,2,3,4,5,6,7,8,9,10};
    // filter
    auto odd=v|std::views::filter([](int x)
    {
        return (x%2==1);
    });
    
    cout<<"after filter"<<endl;
    for(auto x:odd)
    cout<<x<<" ";
    cout<<endl;
    //transform
    
    auto modify=v|std::views::transform([](int x)
    {
        return x+10;
    });
    cout<<"after transform "<<endl;
    for(auto x:modify)
    cout<<x<<" ";
    cout<<endl;
    
    //skip elements;
    auto skip=v|std::views::drop(5);
    cout<<"after sking elements"<<endl;
    for(auto x:skip)
    cout<<x<<" ";
    cout<<endl;
    
    // take
    
    auto take_value=v|std::views::take(4);
    cout<<"after taking elements"<<endl;
    for(auto x:take_value)
    cout<<x<<" ";
    cout<<endl;
    
    auto rev=v|std::views::reverse;
    cout<<"after reverse"<<endl;
    for(auto x:rev)
    cout<<x<<" ";
    cout<<endl;
    
    map<int,string>mp={{1,"abcd"},{2,"efgh"},{3,"ijkl"},{4,"wxyz"}};
    auto key=mp|std::views::keys;
    cout<<"key elements in map"<<endl;
    for(auto x:key)
    cout<<x<<" ";
    cout<<endl;
    
    auto value=mp|std::views::values;
    cout<<"values elements in map"<<endl;
    for(auto x:value)
    cout<<x<<" ";
    cout<<endl;
    auto f=v|std::views::take(4)|std::views::filter([](int x)
    {
        return (x%2==1);
    });
    for(auto x:f)
    cout<<x<<" ";
    cout<<endl;
}
