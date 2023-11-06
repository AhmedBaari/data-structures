#include <iostream>
using namespace std;

class bubbleSorting
{
    int *myArray;
    int last;
    int current;
    int size;

public:
    bubbleSorting()
    {
        myArray = new int[5];
        myArray[0] = 3;
        myArray[1] = 4;
        myArray[2] = 1;
        myArray[3] = 2;
        myArray[4] = 6;
        last = 5;
        current = 0;
        size = 5;
    }

    void swap(int a, int b, int array[])
    {
        int temp;
        temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }

    void bubbleSort()
    {
        bool sorted = false;
        current = 0;
        while (sorted == false && current < size - 1)
        {
            sorted = true;
            for (int walker = 0; walker < size - current - 1; walker++)
            {
                if (myArray[walker] > myArray[walker + 1])
                {
                    sorted = false;
                    swap(walker, walker + 1, myArray);
                }
            }
            current++;
        }
    }

        void display()
        {
            for (int i = 0; i < last; i++)
            {
                cout << myArray[i] << " ";
            }
        }
    };

int main()
{
    bubbleSorting mySort;
    mySort.display();
    mySort.bubbleSort();
    cout << endl;
    mySort.display();
}