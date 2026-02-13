#include<iostream>
#include<queue>
using namespace std;
struct process
{
int id;
int burstTime;
int remining_time;
};
int main()
{
queue<process>p;
p.push({1,5,6});
p.push({2,4,7});
p.push({3,2,5});

int currtime=0;
 int timequantum=2;
while(!p.empty())
{
process &q=p.front();
cout<<"exceting p"<<p.id<<"at time"<<currtime;

if(p.remining_time>timequantum)
{
currtime+=timequantum;
p.remining_time-=timequantum;
cout<<"for"<<timequantum<<"units"<<endl;
}
else
{
currtime += q.remining_time;
std::cout << " for " << q.remining_time << " units (Finished)\n";
q.remining_time = 0;
}
q.pop();
}
}



