#include<iostream>
#include<array>
#include<cstdlib>
using  namespace std;
int main()
{
	int a1[3];
	cout<<"enter sensor data for array1"<<endl;
	for(int i=0;i<3;i++)
		cin>>a1[i];


	int a2[2];
	cout<<"enter sensor data for array2"<<endl;
	for(int i=0;i<2;i++)
		cin>>a2[i];

	int a3[4];
	cout<<"enter sensor data for array3"<<endl;
	for(int i=0;i<4;i++)
		cin>>a3[i];

	int **p=new int*[3];
	p[0]=a1;
	p[1]=a2;
	p[2]=a3;

	int size[3]={3,2,4};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<size[i];j++)
		{
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}

