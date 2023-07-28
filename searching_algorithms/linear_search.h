#include <iostream>
using namespace std;

void LinearSearch(int array[], int size, int value){
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            cout << "Searched value " << value << " found at position " << i + 1 << endl;
            return;
        }
    }
    cout << "Searched value " << value << " not found" << endl;
}