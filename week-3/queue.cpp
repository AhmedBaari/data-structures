#include <iostream>
using namespace std;

class Queue {
	int QUEUE[]; // array as stack
	int front; // exit point
	int rear; // entry point
	int size; // size of stack;
	
public: 
	Queue():front(-1),rear(-1),size(5){
		QUEUE = new int[5];
	}
	
	bool isEmpty () {
		if(front == -1 || rear == -1) {
			cout << "Queue is empty" << endl;
			return true;
		} else {
			return false;
		}
	}
	
	bool isFull() {
		if(rear >= size-1) {
			cout << "Queue is full" << endl;
			return true;
		} else {
			return false;
		}
	}
	
	int enqueue(int element) {
		if (isFull()) return false;
		
		if (front == -1) front++;
		rear++;
		
		QUEUE[rear] = element;
	}
	
	int dequeue() {
		if (isEmpty()) return false;
		
		int temp = QUEUE[front];
		
		if (rear == front) front=rear=-1;
		else front++;
		
		cout << "Dequeued element: " << temp;
	}
	
	
		int menu () {
		int element, choice;
		
		do {
			cout << "\n 1. Enqueue \n 2. Dequeue \n 3. exit\n Enter a choice: ";
			cin >> choice;
			
			int tempElement;
			
			// Declarations are not allowed inside switch case
			switch (choice) {
				case 1:
					
					cout << "Enter an element to enqueue: ";
					cin >> tempElement;
					enqueue(tempElement);
					break;
				case 2: 
					dequeue();
					break;
				case 3:
					cout << "Bye" << endl;
					break;
				
				} 
			}  while (choice !=3);
	}	
	
};

int main () {
	Queue Q1;
	Q1.menu();
}
