#include<iostream>
using namespace std;
template<class T,size_t N>
class myarray
{
	T a[N];
	public:
	size_t size()
	{
		return N;
	}

	int & operator[](int index)
	{
		return a[index];
	}
	const int & operator[](int index)const
	{
		return a[index];
	}

	int at(int index)
	{
		if(index>=N)
			throw out_of_range("myarray");
		return a[index];
	}
	const int at(int index)const
	{
		if(index>=5)
			throw out_of_range("myarray");
		return a[index];
	}
	int front()
	{
		return a[0];
	}
	int back()
	{
		return a[N-1];
	}
	int* begin()noexcept
	{
		return a;	
	}
	int* end()noexcept
	{
		return a+N;
	}
	void fill(int x)
	{
		for(int i=0;i<N;i++)
			a[i]=x;
	}
	bool empty()
	{
		if(N<=0)
			return true;
		else
			return false;
	}

};
int main()
{
	myarray<int,5>arr;

	for(int i=0;i<arr.size();i++)
		arr[i]=i+10;
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	cout<<arr.at(3)<<endl;

	cout<<arr.front()<<endl;
	cout<<arr.back()<<endl;
	for(auto i:arr)
		cout<<i<<" ";
	cout<<endl;

	arr.fill(10);
	for(auto i:arr)
		cout<<i<<" ";
	cout<<endl;
/*myarray<int,0>arr1;
	if(arr1.empty())
		cout<<"array is empty"<<endl;
	else
		cout<<"array has element"<<endl;*/
	
	arr.sort(arr.begin(),arr.end());


}
