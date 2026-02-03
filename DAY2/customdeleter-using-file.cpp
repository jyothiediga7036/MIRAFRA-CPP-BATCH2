#include<iostream>
#include<memory>
using namespace std;
class file
{
    public:
    void operator()(FILE *p)const
    {
        if(p)
        {
            cout<<"closing file custom deleter"<<endl;
            fclose(p);
        }
    }
};
int main()
{
    unique_ptr<FILE ,file>p(fopen("data","w"));
    if(p)
    cout<<"file is opened sucessfully"<<endl;
    return 0;
}