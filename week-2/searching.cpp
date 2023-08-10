#include <iostream>
using namespace std;

class search {
private:
	int linearIterativeArray[15] = {3,6,2,16,78,34,23,56,99,27,13,89,57,33,25};
	
	int linearRecursiveArray[15] = {3,6,2,16,78,34,23,56,99,27,13,89,57,33,25};
	
	int binaryIterativeArray[15] = {2,3,6,13,16,23,25,27,33,34,56,57,78,89,99};
	int last = 14;
	int searchKey = 99;
	
public:
	int linearIterativeSearch () {
		
		int index = 0;
		
		while (index <= last && linearIterativeArray[index] != searchKey) {
			index++;
		}
		
		if (index <= last) {
			cout << "linear Iterative Search Found at: " << index << endl;
			return true;
		} else {
			return false;
		}
	
	}
	
	int linearRecursiveSearch(int index = 0) {
		
		if (index > last) return false;
		
		else if (linearRecursiveArray[index] == searchKey) {
			cout << "linear Recursive Search Found at: " << index << endl;
			return true;
		}
		
		else return linearRecursiveSearch(++index);
	}
	
	int binaryIterativeSearch(int first = 0, int last = 14) {
	
		while (first <= last) {
			int mid = (first + last) / 2;
		
			if (binaryIterativeArray[mid] < searchKey) {
				first = mid + 1;
			} else if (binaryIterativeArray[mid] > searchKey) {
				last = mid - 1;
			} else {
				cout << "binary Iterative Search Found at: " << mid << endl;
				return true;
			}
		}
		return false;
	}
	
	int binaryRecursiveSearch() {
		// Will Finish This Later
	}

};


int main () {

	search S1;
	
	S1.linearIterativeSearch();
	S1.linearRecursiveSearch();
	S1.binaryIterativeSearch();

}
