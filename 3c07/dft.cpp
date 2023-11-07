#include<iostream>
using namespace std;

struct graphVertex;
struct graphArc;

struct graphHead
{
int count;
graphVertex* first;
};

struct graphVertex
{
graphVertex next;
int data;
bool process;
bool inStack;
graphArc first;
};

struct graphArc
{
graphVertex destination;
graphArc nextarc;
};

class dft
{

graphHead create()
{
graphHead head=new graphHead();
head->count=0;
head->first->NULL;
return head;
}

insertVertex(graphHead head,int datain)
{
graphVertex vertex=new graphVertex();
vertex->data=datain;
vertex->process=false;
vertex->inStack=false;
vertex->next=NULL;
vertex->first=NULL;
head->count++;
if(head->first==NULL)
	head->first=vertex;
else
	
}

