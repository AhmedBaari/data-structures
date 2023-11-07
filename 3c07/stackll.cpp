#include <iostream>
using namespace std;

struct node
{
    int data;
    node*link;
};

struct head
{
    int count;
    node*top;
};

class STACK
{
    head* slink;
    public:
    void create()
    {
	slink=new head;
	slink->count=0;
	slink->top=NULL;
    }
    bool push(int datain)
    {
	node* newnode=new node;
	if(newnode==NULL)
	{
	    cout<<"Overflow";
	    return false;
	}
	else
	{
    	    newnode->data=datain;
	    newnode->link=slink->top;
	    ++(slink->count);
	    slink->top=newnode;
	    return true;
	}
    }
    int dataout;
    bool pop()
    {
	if(slink->top==NULL)
	{
	    cout<<"Stack is empty";
	    return false;
    	}
	else
	{
	    dataout=slink->top->data;
	    node* temp=slink->top;
	    slink->top=temp->link;
	    delete temp;
	    --(slink->count);
	    return true;
	}
    }
    void display()
    {
	if(slink->top==NULL)
	    cout<<"The stack is empty";
	else
	{
	    node* temp=slink->top;
	    while(temp!=NULL)
	    {
		cout<<temp->data;
		temp=temp->link;
	    }
	}
    }
    bool isempty()
    {
	if(slink->top==NULL)
	    return true;
	else
	    return false;
    }
    bool isfull()
    {
	node*temp=new node;
	if(temp!=NULL)
	{
	    delete temp;
	    return false;
	}
	else 
	    return true;
    }
};

int main()
{
    STACK s;
    int ele;
    s.create();
    cout<<"1 for push \n2 for pop \n3 for display \n4 for isempty  \n5 for isfull \n0 for exit ";
    int ch=1;
    while(ch!=0)
    {
	cout<<"\nEnter your choice: ";
	cin>>ch;
	switch(ch)
	{
	    case 1:
		cout<<"Enter the element to be pushed: ";
		cin>>ele;
		if(s.push(ele)==true)
		    cout<<ele<<" is pushed";
		break;
	    case 2:
		if(s.pop()==true)
		    cout<<s.dataout<<" is popped";
		break;
	    case 3:
		s.display();
		break;
	    case 4:
		if(s.isempty()==true)
		    cout<<"The stack is empty";
		else if(s.isempty()==false)
		    cout<<"The stack is not empty";
		break;
	    case 5:
		if(s.isfull()==true)
		    cout<<"The stack is full";
		else if(s.isfull()==false)
		    cout<<"The stack is not full";
		break;
	    default:
		break;
	}
    }
}
		
