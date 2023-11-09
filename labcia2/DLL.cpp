#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prevNode;
    node *nextNode;
};

struct list
{
    int count;
    node *first;
    node *last;
};

class DLL
{
    list *headnode;

    public:
    DLL () {
        headnode = new list;
        headnode->count = 0;
        headnode->first = NULL;
        headnode->last = NULL;
    }

    bool searchList (int target) {
        node *prev = NULL;
        node *runner = headnode->first;

        bool found;
        while (runner != NULL && target > runner->data)
        {
            prev = runner;
            runner = runner->nextNode;
        }
        if (runner == NULL) {
            found = false;
        } else {
            if (target == runner->data) {
                // FOUND
                found = true;
            } else {
                found = false;
            }

        }
        return found;
        }

    int insertDLL (int target) {
        // if full DLL, return 0

        bool found = searchList(target);
        if (found)
            return 0;

        (headnode->count)++;

        // creating a new node with the details
        node *newNode = new node;
////////////////
        node *prev = NULL;
        node *runner = headnode->first;

        bool found;
        while (runner != NULL && target > runner->data)
        {
            prev = runner;
            runner = runner->nextNode;
        }
        if (runner == NULL)
        {
            found = false;
        }
        else
        {
            if (target == runner->data)
            {
                // FOUND
                found = true;
            }
            else
            {
                found = false;
            }
        }
        if (found == false)
            return 0;
        ////////////////////
        // Insert in beginning 
        if (prev == NULL) {
            newNode->prevNode = NULL;
            newNode->nextNode = headnode->first;
            (headnode->first) = newNode;
        } else {
            newNode->nextNode = runner;
            newNode->prevNode = prev;
            prev->nextNode = newNode;

        }
        if (runner == NULL) {
            headnode->last = newNode;
        } else {
            runner->prevNode = newNode;
        }
        return 1;
    }

    bool deleteDLL (int target) {
        node *prev = NULL;
        node *runner = headnode->first;

        bool found;
        while (runner != NULL && target > runner->data)
        {
            prev = runner;
            runner = runner->nextNode;
        }
        if (runner == NULL)
        {
            found = false;
        }
        else
        {
            if (target == runner->data)
            {
                // FOUND
                found = true;
            }
            else
            {
                found = false;
            }
        }
        if (found == false)
            return false;

        // Delete the node
        if (prev == NULL) {
            // Deleting the first node
            headnode->first = runner->nextNode;
            if (runner->nextNode != NULL) {
                runner->nextNode->prevNode = NULL;
            }
        } else {
            prev->nextNode = runner->nextNode;
            if (runner->nextNode != NULL) {
                runner->nextNode->prevNode = prev;
            }
        }
        delete runner;
        return true;
    }
};