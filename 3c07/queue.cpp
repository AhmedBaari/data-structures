#include<iostream>
using namespace std;

class queue
{
int *a;
int f,r,size;
public:
queue()
{
    cout << "Enter size of queue :";
    cin >> size;
    a = new int (size);
    f = -1;
    r = -1;
}

void enqueue()
{
    int ele;
    if (r >= size-1)
	cout << "Queue is full\n";
    else
    {
	cout << "Enter the element to be added ";
	cin >> ele; 
   	if (f==-1)
	    f++;
	r++;
	a[r] = ele;
    }
}
void dequeue()
{
    if(f==-1&&r==-1)
	cout<<"Queue is empty";
    else
    {
	int temp=a[f];
	if(r==f)
	    r=f=-1;
	else
	   {
		 f=f+1;
		}
	cout<<"The element removed is: "<<temp;
    }
}
void queuefront()
{
	if(f==-1||r==-1)
		cout<<"There is no front element";
	else
	cout<<"The front element is: "<<a[f];

}
void queuerear()
{
	if(f==-1||r==-1)
		cout<<"There is no rear element ";
	else
		cout<<"The rear element is: "<<a[r];
}
bool emptyqueue()
{
	bool empty;
	if(f==-1&&r==-1)
		empty=true;	
	else
		empty=false;
	return empty;
}
bool fullqueue()
{
	bool full;
	if(r==(size-1))
		full=true;
	else
		full=false;
	return full;
}
void queuecount()
{
	if(r==-1&&f==-1)
		cout<<"The queue is empty";
	else
		cout<<"The count is "<<(r-f+1);
}
};
int main()
{
    queue q;
    int ch=1;
    while(ch!=0)
    {
	cout<<"\n Enter 1 for enqueue \n 2 for dequeue \n 3 for queue front \n 4 for queue rear \n 5 for empty queue \n 6 for full queue \n 7 for count\n";
	cin>>ch;
	switch(ch)
	{
	    case 1:
	    {
			q.enqueue();
			break;
	    }
	    case 2:
	    {
			q.dequeue();
			break;
	    }
	    case 3:
	    {
	    	q.queuefront();
	    	break;
	    }
	    case 4:
	    {
	    	q.queuerear();
			break;
	    }
	    case 5:
	    {
	    	if(q.emptyqueue()==true)
	    		cout<<"The queue is empty";
	    	else if(q.emptyqueue()==false)
				cout<<"the queue is not empty";	
			break;
		}
		case 6:
		{
			if(q.fullqueue()==true)
				cout<<"The queue is full";
			else if(q.fullqueue()==false)
				cout<<"The queue is not full";
			break;	
		}	
		case 7:
		{
			q.queuecount();
			break;
		}
		default:
			break;
	}
    }
}
      
