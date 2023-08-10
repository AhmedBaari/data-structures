#include <iostream>
using namespace std;

class sorting {
private:
	int initialArray[15] = {3,6,2,16,78,34,23,56,99,27,13,89,57,33,25};
	int selectionArray[15] ={3,6,2,16,78,34,23,56,99,27,13,89,57,33,25};
	int bubbleArray[15] = {3,6,2,16,78,34,23,56,99,27,13,89,57,33,25};
	int insertionArray[15] = {3,6,2,16,78,34,23,56,99,27,13,89,57,33,25};
	
	int current = 0;
	int smallest = 0;
	int walker = 0;
	int size = 15;
		
public:
	void swap (int a, int b, int array[]) {
		int temp;
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;
	}
	
	void printInitialArray () {
		cout << "INITIAL ARRAY: ";
		for (int i=0; i !=size ; i++) {	
			cout << initialArray[i] << " ";
		}
		cout << endl;
	}
	
	void selectionSorting () {
		for (current = 0 ; current < size ; current++ ) {
			smallest = current;
			for (walker = current ; walker != size ; walker++) {
				if ( selectionArray[walker] < selectionArray[smallest] ) {
					smallest = walker;
				}
			}
			swap(current, smallest, selectionArray);
		}
		
		cout << "SELECTION SORTED ARRAY: ";
		for (int i=0; i !=size ; i++) {
			cout << selectionArray[i] << " ";
		}
		cout << endl;
	}
	
		
	
	void bubbleSorting () {
		bool sorted = false;
		current = 0;
		while (sorted == false && current < size-1) {
			sorted = true;
			for (walker = 0 ; walker < size-current-1 ; walker++) {
				if ( bubbleArray[walker] > bubbleArray[walker+1] ) {
					sorted = false;
					swap(walker, walker+1, bubbleArray);
				}
			}
			current++;
		}
		
		cout << "BUBBLE SORTED ARRAY: ";
		for (int i=0; i <size ; i++) {
			cout << bubbleArray[i] << " ";
		}
		cout << endl;
	}
	

	void insertionSorting () {
		current = 1; walker = 0; smallest = 0;
		int hold = 0;
		
		for (current = 1 ; current < size ; current ++ ) {
			hold = insertionArray[current];
			walker = current-1;
			
			while ( walker >= 0 && hold < insertionArray[walker] ) {
				insertionArray[walker+1] = insertionArray[walker];
				walker--;
			}
		
			insertionArray[walker+1] = hold;
			
		}
	
		cout << "INSERTION SORTED ARRAY: ";
		for (int i=0; i !=size ; i++) {
			cout << insertionArray[i] << " ";
		}
		cout << endl;


	}
	
	

};



int main () {
	sorting s1;
	s1.printInitialArray();
	s1.selectionSorting();
	s1.bubbleSorting();
	s1.insertionSorting();
}

