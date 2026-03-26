#include<iostream> 
using  namespace std;
struct st
{
	mutable int index;
	volatile double value;
};
st fun()
{
	return st({2,3.4});  // created object and initialized to index,values
}
int main()
{
	const auto[index,value]=fun(); // creating an object through function 
	cout<<index<<"->"<<value<<endl;

	index =-4;
	//value =9.7; //error
	cout<<index<<"->"<<value<<endl;

	return 0;
}

