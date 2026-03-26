#include<vector>
using namespace std;
void print(span<int>s,string name)
{
    cout<<name<<" :";
    for(auto x:s)
    cout<<x<<" ";
    cout<<endl;
}
int main()
{
    vector<int>v={1,2,3,4,5};
    span<int>s(v);
    print(s,"total array");
    
    span<int>p=s.first(3);
    print(p,"first_element");
    
    span<int>q=s.last(3);
    print(q,"last_element");
    
    span<int>n=s.subspan(2,2);
    print(n,"subspan");
    
   // cout<<s.at(3)<<endl;   // error becoz its implemented in c++26
} 
