#include<iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};

struct headnode
{
	int count;
	node* first;
	headnode()
	{
		count=0;
		first=NULL;
	}
};

class hashing
{
	int size;
	headnode** hashtable;
	public:
	hashing(int n)
	{
		size=n;
		hashtable=new headnode*[n];
		for(int a=0;a<n;a++)
		{
			hashtable[a]=new headnode();
		}
		cout<<"Hash table is  created\n";
	}
	node* createNode(int x)
	{
		node* newNode=new node();
		newNode->data=x;
		newNode->link=NULL;
		return newNode;
	}
	void insert(int x)
	{
		int pos;
		pos=x%size;
		node* temp=createNode(x);
		temp->link=hashtable[pos]->first;
		hashtable[pos]->first=temp;
		(hashtable[pos]->count)++;
		cout<<x<<" is inserted at "<<pos<<endl;
	}
	void deletehash(int x)
	{
		int pos;
		node*delNode=NULL;
		pos=x%size;
		delNode=hashtable[pos]->first;
		node*pred=NULL;
		bool a=true;
		while(delNode!=NULL)
		{
			if(delNode->data==x)
			{
				if(pred==NULL)
					hashtable[pos]->first=delNode->link;
				else
					pred->link=delNode->link;
				(hashtable[pos]->count)--;
				cout<<"Element deleted successfully\n";
				a=false;
			}
			pred=delNode;
			delNode=delNode->link;
		}
		if(a==true)
			cout<<"Element is not found in the hash table"<<endl;
		
	}	
	void search(int x)
	{
		int pos=x%size;
		int locn;
		bool a=true;
		node* searchNode=createNode(x);
		searchNode=hashtable[pos]->first;
		while(searchNode!=NULL)
		{
			if(searchNode->data==x)
			{
				locn=pos;
				cout<<"Element "<<x<<" found at "<<locn<<endl;
				a=false;
			}
			searchNode=searchNode->link;
		}
		if(a==true)
			cout<<"Element not found"<<endl;
	}
	void display()
	{
		node* temp=new node();
		for(int w=0;w<size;w++)
		{
			temp=hashtable[w]->first;
			cout<<"The elements in "<<w<<" are:\n";
			while(temp!=NULL)
			{
				cout<<temp->data<<endl;
				temp=temp->link;
			}
		}
	}
};

int main()
{
	int ch=1;
	int size;
	cout<<"Enter the size of the hash table ";
	cin>>size;
	hashing h(size);
	cout<<"Enter 1 for insertion , 2 for deletion, 3 for searching , 4 for display , 5 for exit"<<endl;
	while(ch!=0)
	{
		cout<<"Enter your choice :"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				int x;
				cout<<"Enter the element to be inserted :";
				cin>>x;
				h.insert(x);
				break;
			case 2:
				int y;
				cout<<"Enter the element to be deleted :";
				cin>>y;
				h.deletehash(y);
				break;
			case 3:
				int z;
				cout<<"Enter the element to be searched :";
				cin>>z;
				h.search(z);
				break;
			case 4:
				cout<<"The contents of the hastable are :\n";
				h.display();
				break;
			case 0:
				break;
			default:
				cout<<"Invalid choice";
				break;
		}
	}
}

		
			
		


