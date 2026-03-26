#include<iostream>
using namespace std;
class myvector
{
	int *a;
	int s;
	int cp;
	public:
	myvector(int *p=nullptr,int x=0,int y=0)
	{
		a=p;
		s=x;
		cp=y;

		cout<<"constructor"<<endl;
	}
	~myvector()
	{
		cout<<"destructor"<<endl;
		delete []a;
	}
	int size()
	{
		return s;
	}
	int capacity()
	{
		return cp;
	}
	void push_back(int d)
	{
		if(s==cp)
			grow();
		a[s++]=d;
	}
	void grow()
	{
		int newcp=(cp==0)?1:cp*2;
		int *p=new int[newcp];
		for(int i=0;i<s;i++)
			p[i]=a[i];
		delete []a;
		a=p;
		cp=newcp;
	}
	int& operator[](int index)
	{
		if(index>=s)
			throw out_of_range("myvector");
		return a[index];
	}
	void emplace_back(int d)
	{
		if(cp<s)
			grow();
		a[s++]=d;
	}
	void clear()
	{
		/*for(int i=0;i<N;i++)
		{
			s--;
			delete a[i];
		}*/
		//delete [] a;
		//int *p=a;
		//delete []a;
		//p=nullptr;
		a=nullptr;;
		s=0;
	}
	int* begin()noexcept
	{
		return a;
	}
	int* end()noexcept
	{
		return a+s;
	}
	void erase(int pos)
	{
		int*p=new int[s];
		for(int i=0;i<s;i++)
		{
			if(i==pos)
			{
				for(int j=i;j<s;j++)
					a[j]=a[j+1];
			}
		}
		s--;
	}
	void erase(int*p)
	{
		if(p>=a+s)
			return;
		for(int *q=p;q!=a+s;q++)
			*q=(*(q+1));
		s--;
	}
	int at(int index)
	{
		if(index>=s)
			throw out_of_range("myvector");
		return a[index];
	}
	int front()
	{
		return a[0];
	}
	int back()
	{
		return a[s-1];
	}
	void fill(int x)
	{
		for(int i=0;i<s;i++)
			a[i]=x;
	}
	void pop_back()
	{
		int *p=new int[s-1];
		for(int i=0;i<s-1;i++)
			p[i]=a[i];
		delete []a;
		a=p;
		s--;
	}
	void shrink_to_fit()
	{
		int *p=new int[s];
		for(int i=0;i<s;i++)
			p[i]=a[i];
		delete [] a;
		a=p;
		cp=s;
	}
	bool empty()
	{
		if(s==0)
			return true;
		else
			return false;
	}
	void insert(int *p,int d)
	{
		if(p>a+s)
			return;
		if(s==cp)
			grow();
		for(int*q=a+s;q>p;q--)
			*q=(*(q-1));

		*p=d;
		++s;
	}


};
int main()
{
	myvector v;
	cout<<"size="<<v.size()<<endl;
	cout<<"capacity="<<v.capacity()<<endl;

	v.push_back(10);
	cout<<"size="<<v.size()<<endl;
	cout<<"capacity="<<v.capacity()<<endl;
	
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;

	cout<<"size="<<v.size()<<endl;
	cout<<"capacity="<<v.capacity()<<endl;
	v.emplace_back(100);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;

	cout<<"size="<<v.size()<<endl;
	cout<<"capacity="<<v.capacity()<<endl;
//	v.pop_back();
//	v.erase(2);
//	v.shrink_to_fit();
//	v.erase(v.end()-1);	
	v.insert(v.begin()+2,32);
	cout<<"size="<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
	cout<<"capacity="<<v.capacity()<<endl;

/*	v.clear();
	cout<<"size="<<v.size()<<endl;
	cout<<"capacity="<<v.capacity()<<endl;*/

	if(v.empty())
		cout<<"vector empty"<<endl;
	else
		cout<<"vector not empty"<<endl;



}

