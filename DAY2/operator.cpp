 #include<iostream>
 using namespace std;
 class base
 {
    int x;
    int y;
    public:
    void set()
    {
        cout<<"enter the values"<<endl;
        cin>>x>>y;
    }
    void get()
    {
        cout<<"x="<<x<<" "<<"y="<<y<<endl;
    }
    base operator +(base &t)
    {
        base m;
        m.x=x+t.x;
        m.y=y+t.y;
        return m;
    }
 };
 int main()
 {
     base b1;
     b1.set();
     b1.get();
     base b2;
     b2.set();
     b2.get();
     base b3=b1+b2;
     b3.get();
 }