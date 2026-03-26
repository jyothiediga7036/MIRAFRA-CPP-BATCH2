#include<iostream>
#include<memory>
using namespace std;
class sensor
{
	int temp=24;
	public:
	sensor()
	{
	}
	void data(shared_ptr<sensor>s)
	{
		cout<<s->temp<<endl;
	}
	void logger(shared_ptr<sensor>s)
	{
		cout<<s->temp<<endl;
	}
	void controlled(shared_ptr<sensor>s)
	{
		cout<<s->temp<<endl;
	}

};
int main()
{
	shared_ptr<sensor>p=make_shared<sensor>();
	data(sensor);
	logger(sensor);
	controlled(sensor);
}
