#include <iostream>
using namespace std;

// STACK IN LINKEDLIST
/* In this code, we will do the push and pop from the head's side 

HEAD ->  💠 -> D -> C -> B -> A
         ^^^
          E

*/

// All linked lists have a head structure and a node structure
struct node {
    int data; // Data of the node.
    node *link;// Pointer to next node in list or NULL if last element is reached.
};

struct head {
    int count;
    node *top; // Highest Node
};

class stackLinkedList {
    head *headnode;

public:



    // --1-- CREATE STACK
    void createStack () {
        // 1: Allocate memory for stack head
        headnode = new head();

        // 2: Set count to 0
        headnode->count = 0;

        // 3: Set top to null
        headnode->top = NULL;

        // 4: Return stack head ❌
    }

    // --2-- PUSH STACK DESIGN
    bool pushStack (int data) {
        // 1: Allocate new node
        node *nextNode = new node;

        if (!nextNode)
            return false;

        // 2: Store data in new node
        nextNode->data = data;

        // 3: Make current top node the second node
        nextNode->link = headnode->top;

        // 4: make new node the top
        headnode->top = nextNode;

        // 5: increment stack count
        ++(headnode->count);

        return true;
    }

    // --3-- POP STACK
    bool popStack (int &dataOut) {
        
        // X: Check if stack is empty
        if(isEmpty())
            return false;
        else {
            // A temporary pointer ponting to the to-be-popped node
            node *temp = headnode->top;

            // 1: Set dataOut to data in top node
            dataOut = temp->data;

            // 2: Make second node the top node
            headnode->top = temp->link;

            // 3: Decrement stack count
            --(headnode->count);

            // 4: return success
            return true;
        }
    }

    // --4-- STACK TOP
    bool stackTop (int& dataOut){
        // X: Check if stack is empty
        if (isEmpty())
            return false;
        else
        {
            // 1: Set dataout to data in top node
            dataOut = headnode->top->data;

            // 2: set success to true
            return true;
        }
    }

    // --5-- EMPTY STACK
    bool isEmpty()
    {
        if (headnode->count == 0)
            return true;
        else
            return false;
    }

    // --6-- EMPTY STACK
    bool isFull () {
        node *testNode = new node;
        if(testNode) return false;
        return true;
    }

    // --7-- STACK COUNT
    int stackCount()
    {
        return headnode->count;
    }

    // --8-- DESTROY STACK
    bool destroyStack()
    {
        // Check if empty
        if (isEmpty()) {
            return true;
        } else {

            // 1: Loop (Stack not empty)
            while(!isEmpty()) {
                // 1: Delete top node
                node *temp = headnode->top;
                headnode->top = temp->link;
                delete temp;
                --(headnode->count);
            }
            return true;
        }
    }
};

int main() {
    stackLinkedList stack;
    int choice, data, dataOut;
    stack.createStack();
    do
    {
        cout << "\n\n\t\t\tSTACK OPERATIONS\n\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Stack Top\n";
        cout << "4. Stack Count\n";
        cout << "5. Destroy Stack\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                if (stack.pushStack(data))
                    cout << "Data pushed successfully!\n";
                else
                    cout << "Failed to push data! Stack is full.\n";
                break;

            case 2:
                if (stack.popStack(dataOut))
                    cout << "Data popped successfully! Popped data: " << dataOut << endl;
                else
                    cout << "Failed to pop data! Stack is empty.\n";
                break;

            case 3:
                if (stack.stackTop(dataOut))
                    cout << "Top of stack: " << dataOut << endl;
                else
                    cout << "Failed to get top of stack! Stack is empty.\n";
                break;

            case 4:
                cout << "Stack count: " << stack.stackCount() << endl;
                break;

            case 5:
                if (stack.destroyStack())
                    cout << "Stack destroyed successfully!\n";
                else
                    cout << "Failed to destroy stack! Stack is empty.\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}