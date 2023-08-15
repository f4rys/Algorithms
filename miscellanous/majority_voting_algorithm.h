#include <iostream>

using namespace std;

void MajorityVotingAlgorithm(int array[], int N)
{
    int candidate = -1;
    int votes = 0;

    for(int i=0; i<N; i++)
    {
        if(votes == 0)
        {
            candidate = array[i];
            votes = 1;
        }

        else
        {
            if(array[i] == candidate)
            {
                votes++;
            }

            else
            {
                votes--;
            }
        }
    }

    int count = 0;

    for(int i=0; i<N; i++)
    {
        if(array[i] == candidate)
        {
            count++;
        }
    }

    cout << "Array: {";

    for(int i=0; i<N; i++)
    {
        cout << array[i];

        if(i != N-1)
        {
            cout << ", ";
        }
    }
    
    cout << "}" << endl;

    if(count > N/2)
    {
        cout << "The majority element is " << candidate << endl;
    }

    else
    {
        cout << "There is no majority element in the array" << endl;
    }
}