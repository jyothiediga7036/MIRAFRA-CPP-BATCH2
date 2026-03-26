#include<iostream>
#include<ranges>
#include<vector>
#include<algorithm>
int main()
{
    std::vector<int>v={5,1,4,2,3};
    std::ranges::sort(v);
    for(auto x:v)
    std::cout<<x<<" ";
    std::cout<<std::endl;
    
    // find method
    auto i=std::ranges::find(v,3);
    if(i!=v.end())
    {
        std::cout<<*i<<" "<<distance(v.begin(),i)<<std::endl;
    }
    
    //copy elements;
    std::vector<int>v1(v.size());
    std::ranges::copy(v,v1.begin());
    for(auto x:v1)
    std::cout<<x<<" ";
    std::cout<<std::endl;
    
    std::ranges::for_each((v),[](int &x)
    {
        x=x*x;
        std::cout<<x<<" ";
    });
    std::cout<<"\n";
    
    bool b=std::ranges::all_of((v),[](int&x)
    {
        return x>0;
    });
    std::cout<<"all elements are positive "<<std::boolalpha<<b<<std::endl;
    
    
    int c=std::ranges::count(v,4);
    std::cout<<"count="<<c<<std::endl;
    
    
    
}
