#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* nextNode;
};

struct Head {
    int count;
    Node* firstNode;
};

class CircularLinkedList {
    Head* head;
public:
    CircularLinkedList() {
        head = new Head;
        head->count = 0;
        head->firstNode = nullptr;
    }

    void addNode(int data) {
        Node* newNode = new Node;
        newNode->data = data;

        if (head->count == 0) {
            newNode->nextNode = newNode; // Points to itself, circular
        } else {
            newNode->nextNode = head->firstNode->nextNode;
            head->firstNode->nextNode = newNode;
        }

        head->firstNode = newNode;
        head->count++;
    }

    Node* searchNode(int s) {
        Node* temp = head->firstNode;
        do {
            if (temp->data == s)
                return temp;
            temp = temp->nextNode;
        } while (temp != head->firstNode);

        return nullptr; // Not found
    }

    int findNthNodeFrom(int s, int n) {
        Node* startNode = searchNode(s);
        if (startNode == nullptr) {
            std::cout << "Node not found.\n";
            return -1;
        }

        for (int i = 0; i < n; i++) {
            startNode = startNode->nextNode;
        }

        return startNode->data;
    }
};