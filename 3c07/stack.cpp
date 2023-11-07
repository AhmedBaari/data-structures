#include<iostream>
using namespace std;

class STACK
{

int *a;
int top,size;

public:

STACK()
{
    cout << "Enter size of the stack :";
    cin >> size;
    a=new int(size);
    top=-1;
}
void push()
{
    int ele;
    if(top >= (size-1))
	cout << "The stack is full" << endl;
    else
	{
	cout << "Enter the element to be pushed :";
	cin >> ele;
	top=top+1;
	a[top]=ele;
	}
}
void pop()
{
    int temp;
    if(top==-1)
	cout << "The stack is empty" << endl;
    else
	temp = a[top];
	top=top-1;
	cout << "The popped element is " << temp << endl;
}
void stacktop()
{
    if(top==-1)
    	cout << "The stack is empty" << endl;
    else
    	cout << "The top element is " << a[top] << endl;
}
void display()
{
    if(top==-1)
    	cout << "The stack is empty" << endl;
    else
	cout << "The stack elements are :\t";
	for(int i = 0; i <= top; i++)
	    cout << a[i]<<"\t";
}
bool emptystack()
{
	bool empty;
	if(top==-1)
		empty=true;
	else
		empty=false;
	return empty;
}
bool fullstack()
{
	bool full;
	if(top==(size-1))
		full=true;
	else
		full=false;
	return full;
}
};

int main()
{
    STACK S;
    int ch=1;
    while (ch != 0)
    {
	cout << "\n 1 for push \n 2 for pop \n 3 for stacktop \n 4 for display \n 5 for emptystack \n 6 for fullstack \n Enter the choice : ";
   	cin >> ch;
	switch(ch)
	{
	    case 1:
			S.push();
			break;
	    case 2:
			S.pop();
			break;
	    case 3:
			S.stacktop();
			break;
	    case 4:
			S.display();
			break;
	    case 5:
	    {
			if(S.emptystack()==true)
	    		cout<<"The stack is empty";
	    	else if(S.emptystack()==false)
	    		cout<<"The stack is not empty";
				break;
		}
		case 6:
		{
			if(S.fullstack()==true)
				cout<<"The stack is full";
			else if (S.fullstack()==false)
				cout<<"The stack is not full";
			break;
		}
		default:
		break;
		
	}
    }

}


