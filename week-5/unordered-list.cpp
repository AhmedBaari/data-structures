#include <iostream>
using namespace std;

/* An unordered list has only a node and no head 
- We have a pointer "slist" that points to the first node of the list.
*/

struct node {
    int data;
    node *link;
};

class SinglyLinkedListUnordered {
    node *slist;

    SinglyLinkedListUnordered () {
        slist = NULL;
    }

    /* Insert in beginning */
    bool insertInBeginning (int element) {
        // 1: Create new node
        node *nextNode = new node;

        // If no address, then memory full
        if (!nextNode)
        {
            cout << "Memory Full";
            return false;
        }
        
        // 2: Set the data
        nextNode->data = element;

        // 3: Set the link to next element
        nextNode->link = slist; // If slist is null, no next element

        // 4: Set the slist to the current node
        slist = nextNode;
        return true;
        
    }

    /* Insert in end */
    bool insertAtEnd(int element){
        // 1: Create new node
        node *nextNode = new node;

        // Checking for address
        if (!nextNode) {
            cout << "Memory Full" << endl;
            return false;
        }

        // 2: Set the data
        nextNode->data = element;

        // 3: Set link from previous node
        /* For this, we will perform a while loop starting from slist */
        // If no elements, make this the slist
        if (!slist) {
            slist = nextNode;
        } else {
            // Start a new pointer and iterate till we find a null link (last node)
            node *temp = slist; // Start from slist
            
            while (temp->link) { // Getting last node
                temp = temp->link;
            }

            // Now, we reached the last node before nextNode
            temp->link = nextNode;
            return true;

        }
    }

    bool insertAfterValue (int searchTerm, int element) {
        // 1: Create new node
        node *nextNode = new node;

        // Checking for address
        if (!nextNode) {
            cout << "Memory Full" << endl;
            return false;
        }

        // 2: Set the data
        nextNode->data = element;

        // 3: Set link from specific node
        /* For this, we will perform a while loop starting from slist */
        // If no elements, make this the slist
        if (!slist) {
            slist = nextNode;
        } else {
            // Start a new pointer and iterate till we find the search term
            node *temp = slist; // Start from slist
            
            while (!(temp->data=searchTerm && !(temp))) { // GETTING SPECIFIC NODE
                temp = temp->link;
            }

            // If we overshoot the iteration, then alert the problem
            if (!temp) {
                cout << "Invalid search term" << endl;
                return false;
            }

            // TEMP is the node to be before the nextNode
            // AFTER can be the node to be after the nextNode

            node *afterNode = temp->link;

            // Link before node to nextNode
            temp->link = nextNode;
            
            // Link nextNode to afterNode
            nextNode->link = afterNode;

            return true;

            // Now, we reached the node which matches the search term
            temp->link = nextNode;
            return true;

        }
    }    

    /* Deleting an element from the beginning */
    int delBeginning () {
        // Check if there are no elements in the list
        if (!slist) {
            cout << "nothing to delete" << endl;
            return false;
        }

        // 1: Save value in temporary variable
        node *temp = slist;

        // 2: Move slist to next element
        slist = slist->link;

        // 3: Have a copy of the dataout
        int deletedData = temp->data;
        cout << "Deleted " << deletedData;

        // 4: Delete the node using the temporary pointer
        delete temp;

        return deletedData;
    }

    /* Deleting an element from the end */
    int delEnd () {
        // Check if there are no elements in the list
        if (!slist) {
            cout << "nothing to delete" << endl;
            return false;
        }

        /* 1: Get the last node */
        // Start a new pointer and iterate till we find a null link (last node)
        node *temp = slist; // Start from slist
        node *previousNode = NULL; // We will also get the previous node

        while (temp->link) { // Getting last node
            previousNode = temp;
            temp = temp->link;
        }

        // Now, we are in last node

        // 2: Unlink previous node from this node
        previousNode->link = NULL;

        // 3: Have a copy of the dataout
        int deletedData = temp->data;
        cout << "Deleted " << deletedData;

        // 4: Delete the node using the temporary pointer
        delete temp;

        return deletedData;
    }

    void delbyValue(){
        // Coming Soon
    }

    void delbyPosition(){
        // Coming Soon
    }

    void delALL()
    {
        // Coming Soon
    }

    void display()
    {
        // Coming Soon
    }
};

    int main()
    {
        cout << "Hello World";
        // Coming Soon
    }