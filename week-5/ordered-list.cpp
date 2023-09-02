#include <iostream>
using namespace std;

/* Node structure */
struct node {
	int data;
	node *link;
};

/* Head structure */
struct Head {
	int count;
	node *first;
};

class orderedList {
	Head *head;
public:	
	orderedList () {
		// Initializing the head
		head = new Head;
		head -> count = 0;
		head -> first = NULL;
	}
	
	bool search (int query) {
		node *currentNode = head->first;
		node *previousNode = NULL;
		
		/*While loop to iterate and search*/
		while (currentNode !=NULL && currentNode->data <= query) {
			if (currentNode->data == query) {
				return true;
			} else {
				previousNode=currentNode;
				currentNode=currentNode->link;
			}
		}
		return false;
	}
	
	bool insertNode (int query) {
		if (search(query)) return false;
		
		node *insertingNode = new node;
		if (!insertingNode) return false;
		
		insertingNode->data = query;
		
		node *afterNode = head->first;
		node *beforeNode = NULL;
		
		/*While loop to iterate and search*/
		while (afterNode !=NULL && afterNode->data < query) {
			beforeNode=afterNode;
			afterNode=afterNode->link;

		}
		
		insertingNode->link=afterNode;	
		
		if (!beforeNode) {
			head->first=insertingNode;
		} else {
			beforeNode->link = insertingNode;
		}
		
		++(head->count);
		
		
	}
	
	bool deleteNode (int query, int &dataOut) {
		if (!search(query)) return false;
		
		node *deletingNode = head->first;
		node *beforeNode = NULL;
		
		/*While loop to iterate and search*/
		while (deletingNode !=NULL && deletingNode->data < query) {
			beforeNode=deletingNode;
			deletingNode=deletingNode->link;
		}
		
		node *temp = deletingNode;
		dataOut = temp->data;
		
		if(!beforeNode){
			head->first = temp->link;
		} else {
			beforeNode->link = temp->link;
		}
		--(head->count);
		delete temp;
		return true;
	}
};


int main () {
	orderedList myList;
	
	int choice;
	
	do {
	cout << "1: Insert\n2: Delete\nEnter a number:";
	cin >> choice;
	
	switch (choice) {
		int dataOut;
		int inputNumber;
		bool successCheck;
		// Do not delare inside cases
		case 1:	

			cout << "Enter a number: ";
			cin >> inputNumber;
			successCheck = myList.insertNode(inputNumber);
			if(successCheck) cout << "Success!" << endl;
			else cout << "Failed" << endl;
			break;
			
		case 2:
			
			
			cout << "Enter num to delete: ";
			cin >> inputNumber;
			successCheck = myList.deleteNode(inputNumber,dataOut);
			if (successCheck) cout << "Deleted " << dataOut << endl;
			else cout << "FAILED to delete" << endl;
	}
	} while (choice !=0);
	
	return 0;
}
