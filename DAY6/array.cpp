#include<iostream>
#include<array>
#include<iterator>
#include<algorithm>
using namespace std;
void fun(array<int,6>&a)
{
	for(int i=0;i<a.size();i++)
	{
		a[i]=a[i]+10;
	}
}
int main()
{
	array<int,5>arr={2,5,1,9,3};
	sort(arr.begin(),arr.end());
	
	cout<<"after sorting arr"<<endl;
	for(const auto i:arr)
		cout<<i<<" ";
	cout<<endl;

	cout<<arr.at(2)<<endl;
	cout<<arr[3]<<endl;

	array<int,5>arr1={4,8,1,3,7};
	arr.swap(arr1);


	cout<<"after swapping"<<endl;
	for(auto i:arr)
		cout<<i<<" ";
	cout<<endl;

	for(auto i:arr1)
		cout<<i<<" ";
	cout<<endl;

	cout<<arr.front()<<endl; //accesing front element
	cout<<arr.back()<<endl;   // accessing back element

	if(arr.empty())  // array is empty/not
		cout<<"array is empty"<<endl;
	else
		cout<<"array is not empty"<<endl;
	cout<<arr.max_size()<<endl;  // max size of array
	cout<<arr.size()<<endl;   //no of elements

	array<int,6>arr2;
	arr2.fill(0);  //fill all elements with zero 

	array<int,6>::iterator it; 
	for(it=arr2.begin();it!=arr2.end();it++)
		cout<<*it<<" ";
	cout<<endl;

	sort(arr1.rbegin(),arr1.rend());
	for(auto i:arr1)
		cout<<i<<" ";
	cout<<endl;

	fun(arr2);
	cout<<"after function arr2"<<endl;
	for(auto i:arr2)
		cout<<i<<" ";
	cout<<endl;

}


