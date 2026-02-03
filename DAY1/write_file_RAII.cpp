#include<iostream>
#include<fstream>
#include<cstring>
#include<unistd.h> //close()
#include<fcntl.h> //open();
using namespace std;
class File
{
	int fd;
	public:
	File(const char*p)
	{
		fd=open(p,O_WRONLY|O_TRUNC|O_CREAT,0644);
		if(!fd)
			perror("open");
		cout<<fd<<endl;
	}
	void readdata(const char *p)
	{
		read(fd
	}
	~File()
	{
		if(fd>=0)
			close(fd);
	}
};
int main()
{
	File f("data");
	f.writedata("i open the file\n");
	f.writedata("writing something\n");

	File f1("abc");
	f1.writedata("hi friends\n");
	
	cout<<"work done"<<endl;
}
