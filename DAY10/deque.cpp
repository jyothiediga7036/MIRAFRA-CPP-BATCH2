#include<iostream>
using  namespace std;
class deque
{
	int block_size=4;
	int table_size=4;
	int** block_table;
	int start_block;
	int end_block;
	int start_offset;
	int end_offset;
	int cur_size;
	public:
	deque()
	{
		block_table=new int*[table_size];
		for(int i=0;i<table_size;i++)
			block_table[i]=nullptr;

		start_block=end_block=table_size/2;

		block_table[start_block]=new int[block_size];
		start_offset=0;
		end_offset=0;
		cur_size=0;
	}
	void push_back(int d)
	{
		if(end_offset==block_size)
		{
			if(end_block+1>=table_size)
				realloc();
			end_block++;
			block_table[end_block]=new int[block_size];
			end_offset=0;
		}
		block_table[end_block][end_offset++]=d;
		cur_size++;
	}
	void push_front(int d)
	{
		if(start_offset>0)
			start_offset--;
		else
		{
			if(start_block-1<0)
realloc();
			start_block--;
			block_table[start_block]=new int[block_size];
			start_offset=block_size-1;
		}
		block_table[start_block][start_offset]=d;
		cur_size++;
	}
	int operator[](int index)
	{
		int total_offset=start_offset+index;
		int block=start_block+(total_offset/block_size);

		int offset=total_offset%block_size;
		return block_table[block][offset];
	}
	void realloc()
	{
cout<<"reallocation is called"<<endl;
		int newsize=table_size*2;
		int old_start=start_block;
		int old_end=end_block;
		int p_left,p_right;
		p_left=p_right=table_size/2;

		int**p=new int*[newsize]{nullptr};
		int left,right;
		left=right=newsize/2;
		for(int i=left-1,j=p_left;j>=0;i--,j--)
			p[i]=block_table[j];

		for(int i=right,j=p_right;j<table_size;j++,i++)
			p[i]=block_table[j];

		delete []block_table;
		block_table=p;
		start_block=left;
		end_block=left+(old_end-old_start);
		table_size=newsize;
	}

	int size()const
	{
		return cur_size;
	}

	~deque()
	{
		for(int i=0;i<table_size;i++)
		{
			if(block_table[i])
				delete[] block_table[i];
		}
		delete[]block_table;
	}

};


int main()
{
	deque d;
	for(int i=0;i<10;i++)
		d.push_back(i);

	for(int i=10;i<25;i++)
		d.push_front(i);

	for(int i=0;i<d.size();i++)
		cout<<d[i]<<" ";
	cout<<endl;

cout<<"size="<<d.size()<<endl;


	return 0;
}

