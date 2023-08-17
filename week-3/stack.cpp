#include <iostream>
using namespace std;

class Stack {
	int STACK[]; // array as stack
	int top; // highest element's index
	int size; // size of stack; 

public:
	Stack():size(5),top(-1) {
		STACK = new int[5];
	}
	}

	/* Method to push an element into the stack */
	int push (int insertElement) {
		// When stack is full, element cannot be added
		if (top >= size-1) {
			cout << " Stack is full" << endl;
			return false;
		} else {
			top++;
			STACK[top] = insertElement;
			cout << " Element pushed!" << endl;
			return true;
		}
	}
	
	/* Method to pop an element from the stack */
	int pop () {
		// When stack is empty, top is -1
		if (top == -1) {
			cout << " Stack is empty" << endl;
			return false;
		} else {
			int temp;
			temp = STACK[top]; // temporarily storing the top element's value
			top--; // reducing stack by one level
			cout << " Popped " << temp << endl;
			return temp; // returning the popped  value
		}
	}
	
	/* Method to peek the top element from the stack */
	int peek () {
		// When stack is empty, top is -1
		if (top == -1) {
			cout << " Stack is empty" << endl;
			return false;
		} else {
			cout << " Peek element is " << STACK[top] << endl;
			return STACK[top]; // returning the peek value
		}
	}
	
	int display () {
		// When stack is empty there is nothing to display
		if(top == -1) {
			cout << " Stack is empty" << endl;
			return false;
		} else {
			int index = top; //highest to lowest
			cout << " Displaying stack: ";
			while (index >= 0) {
				cout << STACK[index] << " ";
				index--;
			}
		}
		return true;
	}
	
	int menu () {
		int element, choice;
		
		do {
			cout << "\n 1. Push \n 2. POP \n 3. Peek \n 4. Display \n 5. exit\n Enter a choice: ";
			cin >> choice;
			
			int tempElement;
			
			// Declarations are not allowed inside switch case
			switch (choice) {
				case 1:
					
					cout << "Enter an element to push: ";
					cin >> tempElement;
					push(tempElement);
					break;
				case 2: 
					pop();
					break;
				case 3: 
					peek();
					break;
				case 4:
					display();
					break;
				case 5:
					cout << "Bye" << endl;
					break;
				
				}
		} while (choice !=5);
	}
};

int main () {
	Stack s1;
	s1.menu();
}
