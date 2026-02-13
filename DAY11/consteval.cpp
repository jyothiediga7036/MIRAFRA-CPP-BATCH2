#include<iostream>
using  namespace std;
consteval int square(int x)
{
return x*x;
}
int main()
{
int a=square(5);
cout<<"a="<<a<<endl;

int b=10;
int c=square(b);  // error becoz it evaluated at runtime (value assinged at runtime only)
constexpr int b=10;
const int b=10;   //no error bcoz const values are assigned at compile time only;
int c=square(b);
cout<<c<<endl;
return 0;
}
