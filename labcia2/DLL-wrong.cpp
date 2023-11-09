#include <iostream>
using namespace std;

/*
TWO
To perform the following operations on a double linked list,implement a menu driven program.
a.add an integer element to the list
b.display the list
c.get the two node positions,then swap the two node values
d.search a given number 's' from the list. start searching both from first node of the list and from the last node of the list and display to which node, the given number 's' is nearer?(from last or first
*/


struct node {
    int data;
    node *nextNode;
};

struct Head {
    int count;
    node *firstNode;
};

class DLL {
    Head *head;
public:
    DLL () {
        head = new Head;
        head->count = 0;
        head->firstNode = NULL;
    }

    // Add an integer element to the list
    bool insertNode (int data) {
        node *newNode = new node();
        if (!newNode) {
            return false;
        }

        newNode->data = data;
        newNode->nextNode = NULL;

        if (head->count == 0) {
            head->firstNode = newNode;
        } else {
            node *runner = head->firstNode;
            node *prev = NULL;

            while (runner != NULL && data > (runner->data)) {
                prev = runner;
                runner = runner->nextNode;
            }
            if (runner == NULL) {
                
            } else if (newNode->data == runner->data) {
                return true;
            } else {
                newNode->nextNode = runner;
            }
            prev->nextNode = newNode;
            (head->count)++;
            return true;
        }
    }

    // b.display the list
     void displayList () {
        node *runner = head->firstNode;
        if (!runner)
            cout << "BYE" << endl;
        
        while (runner != NULL) {
            cout << runner->data << ", ";
        }
     }
};
int main() {
    DLL dll;
    int choice, data, pos1, pos2, s;
    bool result;

    do {
        cout << "\n\nMENU\n";
        cout << "1. Add an integer element to the list\n";
        cout << "2. Display the list\n";
        cout << "3. Swap two node values\n";
        cout << "4. Search a given number 's' from the list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the integer element to add: ";
                cin >> data;
                result = dll.insertNode(data);
                if (result) {
                    cout << "Element added successfully\n";
                } else {
                    cout << "Failed to add element\n";
                }
                break;
            case 2:
                cout << "The list is: ";
                dll.displayList();
                break;
            case 3:
                cout << "Enter the positions of the nodes to swap: ";
                cin >> pos1 >> pos2;
                // TODO: Implement swapping of node values
                break;
            case 4:
                cout << "Enter the number to search: ";
                cin >> s;
                // TODO: Implement searching of number 's' in the list
                break;
            case 5:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
