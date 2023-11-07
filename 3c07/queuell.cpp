#include<iostream>
using namespace std;

struct node
{
    int data;
    node* link;
};

struct head
{
    int count;
    node* rear;
    node* front;
};

class queue
{
    head* qlink;
    public:
    queue()
    {
	qlink=new head;
	qlink->count=0;
	qlink->rear=NULL;
	qlink->front=NULL;
    }
    	void enqueue(int datain)
	{
	    node* newnode=new node;
	    if(newnode!=NULL)
	    {
		newnode->data=datain;
		newnode->link=NULL;
		if(qlink->count==0)
		    qlink->front=newnode;
		else
		    qlink->rear->link=newnode;
		qlink->rear=newnode;
		++(qlink->count);
	    }
	    else
		cout<<"The stack is full";
	}
	int dataout;
	void dequeue()
	{
	    if(qlink->count==0)
		cout<<"The stack is empty";
	    else
	    {
		dataout=qlink->front->data;
		if(qlink->count==1)
		    qlink->rear=NULL;
		node* temp=qlink->front;
		qlink->front=temp->link;
		delete temp;
	    }
	}
	void display()
	{
	    if(qlink->count==0)
		cout<<"Queue is empty";
	    else
	    {
		node* temp=qlink->front;
		while(temp!=NULL)
		{
		    cout<<temp->data<<" ";
		    temp=temp->link;
		}
	    }
	}
    	void destroy()
	{
	    while(qlink->front!=NULL)
	    {
		node* temp=qlink->front;
		qlink->front=temp->link;
		delete temp;
		--(qlink->count);
    	    }
	    delete qlink;
	}
};
int main()
{
    queue q;
    int ele;
    cout<<"\n1 for enqueue \n2 for dequeue \n3 for display \n4 for destroy \n0 for exit";
    int ch=1;
    while(ch!=0)
    {
	cout<<"\nEnter choice: ";
	cin>>ch;
	switch(ch)
	{
	    case 1:
		cout<<"Enter the element to be added :";
		cin>>ele;
		q.enqueue(ele);
		cout<<ele<<" is added";
		break;
	    case 2:
		q.dequeue();
		cout<<q.dataout<<" is removed";
	    	break;
	    case 3:
		q.display();
		break;
	    case 4:
		q.destroy();
		cout<<"The queue is destroyed";
	    default:
		break;
	}
    }
}
		
    
    


		    

	    
