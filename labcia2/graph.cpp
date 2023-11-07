#include <iostream>
using namespace std;

struct vertex;
struct arc;

/* Head Structure */
struct head {
	int count;
	vertex *firstVertex;
};

/* Vertex Structure */
struct vertex {
	vertex *nextVertex;
	int data;
	bool processed;
	bool inStack;
	arc *firstArc;
};

/* Arc Structure */
struct arc {
	vertex *itsVertex;
	arc *nextArc;
};


class graph {
	// We will control everything using HEAD
	head *GOD;
public:	
	
	// We will start off with an empty head
	graph () {
		GOD = new head;
		GOD->count = 0;
		GOD->firstVertex = NULL;
	}
	
	bool addVertex (int in_data) {
		// Setup

		vertex *baby = new vertex;
		if (!baby) return false;
		
		baby->nextVertex = NULL;
		baby->data=in_data;
		baby->processed=false;
		baby->inStack=false;
		baby->firstArc=NULL;
		

		// Check for duplicate
		if(find(in_data)) return false;
		
		// Final adding procedure
		if (GOD->firstVertex == NULL) {
			GOD->firstVertex = baby;
			
		} else {
			vertex *searcher = new vertex;
		
			searcher = GOD->firstVertex;
			while (searcher->nextVertex != NULL) {
				searcher = searcher->nextVertex;
			} 
			searcher->nextVertex = baby;

		
		}
		GOD->count++;
		return true;
	}
	
	bool find (int query) {
		vertex *searcher = new vertex;
		
		if (GOD->firstVertex == NULL) return false;
		searcher = GOD->firstVertex;
		while (searcher !=NULL && searcher->data != query) {
			searcher = searcher->nextVertex;
		} 
		if (searcher == NULL || searcher->data != query) return false;
		return true;
	}
	
	vertex* getVertex (int query) {
		
		vertex *searcher = new vertex;
		searcher = GOD->firstVertex;
		while (searcher !=NULL && searcher->data != query) {
			searcher = searcher->nextVertex;
		} 
		// warning: I'm not checking if query matches searcher
		return searcher;
	}
	
	void display () {
		
		vertex *searcher = new vertex;
		
		searcher = GOD->firstVertex;
		

		while (searcher !=NULL) {
			cout << searcher->data << ", ";
			searcher = searcher->nextVertex;
		}
	
	}

	bool addArc(int A, int B){
			// Let's make sure both vertices are there
	vertex *vertexA = getVertex(A);
	vertex *vertexB = getVertex(B);

	if (vertexA == nullptr || vertexB == nullptr)
	{
		return false; // One of the vertices doesn't exist
	}

	// A LINKS TO B
	arc *A_linkto_B = new arc;
	A_linkto_B->itsVertex = vertexB;
	A_linkto_B->nextArc = nullptr;

	// Let's add it to A's vertex
	if (vertexA->firstArc == nullptr)
	{
		vertexA->firstArc = A_linkto_B;
	}
	else
	{
		arc *A_runner = vertexA->firstArc;
		while (A_runner->nextArc != nullptr)
		{
			if (A_runner->itsVertex->data == B)
			{
				return true; // The arc already exists
			}
			A_runner = A_runner->nextArc;
		}
		A_runner->nextArc = A_linkto_B;
	}

	// B LINKS TO A
	arc *B_linkto_A = new arc;
	B_linkto_A->itsVertex = vertexA;
	B_linkto_A->nextArc = nullptr;

	// Let's add it to B's vertex
	if (vertexB->firstArc == nullptr)
	{
		vertexB->firstArc = B_linkto_A;
	}
	else
	{
		arc *B_runner = vertexB->firstArc;
		while (B_runner->nextArc != nullptr)
		{
			if (B_runner->itsVertex->data == A)
			{
				return true; // The arc already exists
			}
			B_runner = B_runner->nextArc;
		}
		B_runner->nextArc = B_linkto_A;
	}
	return true; // Arc added successfully
}
};

int main () {

	graph myGraph;
	

	myGraph.addVertex(3);
	myGraph.addVertex(2);
	myGraph.addVertex(5);
	myGraph.addVertex(4);
	myGraph.display();
	
	myGraph.addArc(3,5);
	
}
