#include<iostream>
using namespace std;
int main()
{
	const int *p;
	int *const p1=nullptr;
const int *const p2=nullptr;
	const int &r=p;
	//const int &r=p;  //invalid 
	int *const &r=p1;
	const int * const&r1=p2;
}
