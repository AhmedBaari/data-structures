#include <iostream>
using namespace std;

// Creating the NODE Structure
struct node {
	int data; // we store the data here
	node *slink; //links to next element of the stack, DOES NOT CREATE MEMORY AUTO.LY
};

// Creating the HEAD Structure
struct head {
	int count; // first block has count
	node *top; // first element (top) of linked list is here
};



// Creating the STACK OPERATIONS
class STACK {
	// The stack has a head that controls it
	head *slink; // We can access the head using slink
	
public:
	STACK() {
		/* Initializing the head */
		slink = new head();
		slink -> count = 0; // use arrow functions for pointers
		slink -> top = NULL; // NULL in caps
	}
	
	/* PUSH 
		/OPERATION */
	bool push(int data_in) {
		// Creating a new node using pointer
		node *nextNode = new node;
		/* If nextNode is still null, then no memory available */
		if (!nextNode) {
			cout << "Overflow";
			return false;
		} else {
			/* Everything is fine so far, let's enter the data */
			nextNode -> data = data_in;
			nextNode -> slink = slink-> top; // this links the nextnode to the node on the right
			/* BUT DOUBT: WHAT IF SLINK TOP IS NULL
			
			[HEAD] [NEXTNODE]--->[EXISTING NODE] 
			         ^^^^
			*/
			
			// Incrementing the head's counter
			++(slink -> count);
			
			// Setting the top address
			slink->top = nextNode;
		}
		return true;
	}
	
	/* POP OPERATION */
	int pop () {
		/* Get the top element */
		// If top is null, stack is empty
		if(slink->top == NULL) {
			cout << "Stack empty" << endl;
			return false;
		} else {
			int myData = slink -> top -> data;
			
			--(slink->count); // Decrementing the stack elements count
			slink->top = slink->top->link;
			
			/* 
			
			[HEAD] [NEXTNODE][EXISTING NODE] 
			         ^      -->     ^^^^
			*/

		}
		return myData;	
	}
	
	void display() {
		// A pointer pointing to top element
		node *targetNode = slink->top;
		
		while(targetNode !=NULL) { //DOUBT: top=null??
			cout << (targetNode->data) << "";
			temp = targetNode -> slink; //DOUBT
		}
	}
	
	bool isEmpty() {
		if (slink->top == NULL) return true;
		else return false;
	}
	
	bool isFull() {
		node *nextNode = new node;
		/* If nextNode is still null, then no memory available */
		if (nextNode == NULL) {
			delete nextNode; //WHY THIS ISN'T IN THE NOTE?
			return true;
		} else {
			delete nextNode; 
			return false;
		}
	}
	
	bool stackTop () {
		node *Temp = new node;
		if(isEmpty()) return false;
		
		topElement = (slink->top)->data; //using head's top to point to data of top node
		return true; // DOUBT: PRINT DATA??
	} 

};

int main () {
	STACK berrystack;
	
}
