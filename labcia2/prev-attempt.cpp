/*
Create a circular singly linked list to store some set of numbers. Write and implement an algorithm to search a given number 's' from the list and to find the n th node data from node 's'
*/

#include <iostream>
using namespace std;

struct node {
    int data;
    node *nextNode;
};

struct head {
    int count;
    node *firstNode;
};

class CSLL {
    head *Head;
public:
    CSLL () {
        Head = new head();
        Head->count = 0;
        Head->firstNode = NULL;
    }

    bool insertNumber (int numberData) {
        node *greenie = new node();
        if (!greenie)
            return false;
        greenie->data = numberData;
        greenie->nextNode = NULL;

        /* Ordered Insertion */ 
        // Inserting as the first node
        if (Head->count == 0) {
            Head->firstNode = greenie;
        } else {
            node *runner = Head->firstNode;
            node *previous = NULL;
            while (runner != NULL && (runner->data) < (greenie->data))
            {
                previous = runner;
                runner = runner->nextNode;
            }
            // If last node to insert...
            if (runner != NULL) {
                greenie->nextNode = runner;
            }
        }
        Head->count++;
    }

    // Write and implement an algorithm to search a given number 's' from the list
    node *search(int query) {
        if (Head->count == 0)
            return NULL;
        node *runner = Head->firstNode;

        while (runner != NULL && runner->data <= query) {
            runner = runner->nextNode;
        }
        if(runner->data == query) {
            return runner;
        }
    }

    // find the n th node data from node 's'
    int forwardFind (int query, int forward) {
        node *initial = search(query);
        if (!initial)
            return NULL;

        node *runner = initial;
        for (int i = 0; i < forward; i++)
        {
            runner = runner->nextNode;
        }

        if (!runner)
            return NULL;
        return runner-> data;
    }

    void display () {
        // LATER
    }
};

int main () {
    // LATER
}

// time taken: 20 minutes