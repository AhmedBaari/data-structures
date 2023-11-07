#include<iostream>
using namespace std;

struct student
{
	string name;
	int reg;
	int mark1;
	int mark2;
	int mark3;
	int total;
	student()
	{}
	student(string name1,int regno,int m1,int m2,int m3)
	{
		name=name1;
		reg=regno;
		mark1=m1;
		mark2=m2;
		mark3=m3;
		total=m1+m2+m3;
	}
};

struct node
{
	student s;
	node*link;
	node()
	{}
	node(student s1)
	{
		s.name=s1.name;
		s.reg=s1.reg;
		s.mark1=s1.mark1;
		s.mark2=s1.mark2;
		s.mark3=s1.mark3;
		s.total=s1.total;
		link=NULL;
	}
};

struct headnode
{
	int count;
	node* head;
	headnode()
	{
		count=0;
		head=NULL;
	}
};

class sll
{
	headnode* section=new headnode();
	public:
	bool add(student s)
	{
		node* newnode=new node(s);
		if(newnode!=NULL)
		{
			newnode->link=section->head;
			section->head=newnode;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool display()
	{
		node* temp=section->head;
		if(temp==NULL)
		{
			cout<<"The section has no students";
			return false;
		}
		else
		{
			while(temp!=NULL)
			{
				cout<<temp->s.name<<"\t";
				cout<<temp->s.reg<<"\t";
				cout<<temp->s.mark1<<"\t";
				cout<<temp->s.mark2<<"\t";
				cout<<temp->s.mark3<<"\t";
				temp=temp->link;
				cout<<endl;
			}
			return true;
		}
	}
	node* topstudentdis()
	{
		node* temp1=section->head;
		node* temp2=section->head;
		while(temp1!=NULL)
		{
			if(temp2->s.total<temp1->s.total)
			temp2=temp1;
			temp1=temp1->link;
		}
		return temp2;
	}	
};
void topstudentoverall(sll s1,sll s2,sll s3)
	{
		node* temp=new node();
		if(s1.topstudentdis()->s.total<s2.topstudentdis()->s.total&&s3.topstudentdis()->s.total<s2.topstudentdis()->s.total)
		{
			temp=s2.topstudentdis();
		}
		else if(s2.topstudentdis()->s.total<s1.topstudentdis()->s.total&&s3.topstudentdis()->s.total<s1.topstudentdis()->s.total)
		{
			temp=s1.topstudentdis();
		}
		else
		{
			temp=s3.topstudentdis();
		}
		cout<<"Top student details"<<endl;
		cout<<temp->s.name<<"\t";
		cout<<temp->s.reg<<"\t";
		cout<<temp->s.mark1<<"\t";
		cout<<temp->s.mark2<<"\t";
		cout<<temp->s.mark3<<"\t";
	}
int main()
{
sll s[3];
char sec;
/*student a("hema",1,90,60,80);
student b("achu",2,20,30,40);
student c("aswini",3,40,50,60);
student d("kumar",4,70,80,90);
s[0].add(b);
cout<<endl;
s[0].add(a);
cout<<endl;
s[1].add(c);
cout<<endl;
s[2].add(d);
cout<<endl;
s[0].display();
cout<<endl;
s[1].display();
cout<<endl;
s[2].display();
cout<<endl;
topstudentoverall(s[0],s[1],s[2]);*/
int ch=1;
cout<<"Enter 1 for insert ,2 for display, 3 for calculation of top student ,0 for exit\n";
while(ch!=0)
	{
	switch (ch)
	{
		case 1:
			string name;
			int reg;
			int mark1;
			int mark2;
			int mark3;
			cout<<"Enter the section :"
			cin>>sec;
			cout<<"Enter name of student:"
			cin>>name;
			cout<<"Enter regno of student:"
			cin>>regno;
			cout<<"Enter mark1 of student:"
			cin>>mark1;
			cout<<"Enter mark2 of student:"
			cin>>mark2;
			cout<<"Enter mark3 of student:"
			cin>>mark3;
			if(sec=='a'||sec=='A')
				s[0].add(student(name,regno,mark1,mark2,mark3));
			else if(sec=='b'||sec=='B')
				s[1].add(student(name,regno,mark1,mark2,mark3));
			else if(sec=='C'||sec=='c')
				s[1].add(student(name,regno,mark1,mark2,mark3));
			break;
		case 2:
			cout<<"Enter the section :"
			cin>>sec;
			cout<<"SECTION "<<sec;
			if(sec=='a'||sec=='A')
				s[0].display();
			else if(sec=='b'||sec=='B')
				s[1].display();
			else if(sec=='C'||sec=='c')
				s[1].display();
			break;
		case 3:
			topstudentoverall(s[0],s[1],s[2]);
			break;
		default:
			break;

}

