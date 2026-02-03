#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<string>v={"abcd","ijkl","wxyz"};
	for(const auto &x:v)
		cout<<x<<endl;
}
