#include<iostream>
//#include<atomic>
#include<thread>
using namespace std;
//atomic<int>counter{0};
int counter=0;
void increament()
{
	for(int i=0;i<1000;i++)
		counter++;
}
void decreament()
{
	for(int i=0;i<1000;i++)
		counter--;
}
int main()
{
	thread t1(increament);
	thread t2(decreament);

	t1.join();
	t2.join();

	cout<<"final count="<<counter<<endl;
}

