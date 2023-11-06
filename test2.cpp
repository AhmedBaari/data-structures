#include <iostream>
using namespace std;

int main()
{
    int noOfParticipants;
    cin >> noOfParticipants;

    int targets[noOfParticipants];

    for (int i = 0; i < noOfParticipants; i++)
    {
        cin >> targets[i];
    }

    int j = 0;
    int k = 0;
    int smallestPT = 0;

    while (j < noOfParticipants)
    {
        int smallest = noOfParticipants;
        smallestPT = 0;
        for (int k = 0; k < noOfParticipants; k++)
        {
            if (targets[k] < smallest)
            {
                smallest = targets[k];
                smallestPT = k + 1;
            }
        }
        cout << smallestPT << " ";
        targets[smallestPT - 1] = noOfParticipants + 1;
        j++;
    }
}
