#include<iostream>
#include<ranges>
#include<vector>
using namespace std;
int main()
{
    vector<int>v={24,56,34,41,67};
    
    auto valid_data=v|std::views::filter([](int x)
    {
        return(x<50);
    });
    
    auto invalid_data=v|std::views::filter([](int x)
    {
        return(x>50);
    });
    
    cout<<"valid dataa"<<endl;
    for(auto x:valid_data)
    cout<<x<<" ";
    cout<<endl;
     cout<<"invalid dataa"<<endl;
    for(auto x:invalid_data)
    cout<<x<<" ";
    
    
}
