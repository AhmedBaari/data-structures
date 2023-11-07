#include <iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};

struct head
{
	int count;
	node* lhead;
};

class sll
{
	head* slink;
	public:
	void createlist()
	{
		slink=new head();
		slink->lhead=NULL;
		slink->count=0;
		cout<<"List is created";
	}
	void insertnode(int datain)
	{
		node* ploc=new node();
		node*pnew=new node();
		pnew->data=datain;
		ploc=slink->lhead;
		if(ploc==NULL)
		{
			pnew->link=slink->lhead;
			slink->lhead=pnew;
			cout<<"The data "<<datain<<"is inserted";
		}
		else
		{
			int o;
			while(slink->count!=0)
			{
				if(datain<ploc->data)
				{
					if(datain==ploc->data)
						o=1;
					ploc=ploc->link;
				}
			}
				if(o!=1)
				{
					pnew->link=ploc->link;
					ploc->link=pnew;
					(slink->count)++;
					cout<<"The data "<<datain<<"is inserted";
				}
		}
	}
	void deletenode(int dataout)
	{
		node* ploc=new node();
		node* ppre=new node();
	}
		
		
};

int main()
{
	sll s;
	s.createlist();
	s.insertnode(40);
	s.insertnode(40);
}
	
			
			
		
	

		
		
		
		

