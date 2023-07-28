#include <iostream>
#include <cmath>
using namespace std;

void JumpSearch(int array[], int size, int value){

    int i = 0;
    int b = floor(sqrt(size));

    while(array[min(b,size)-1] < value)
    {
        i= b;
        b += floor(sqrt(size));

        if(i >= size)
        {
            cout << "Searched value " << value << " not found" << endl;
            return;
        }
    }

    while(array[i] < value)
    {
        i++;
        if(i == min(b,size))
        {
            cout << "Searched value " << value << " not found" << endl;
            return;
        }
    }

    if(array[i] == value)
    {
        cout << "Searched value " << value << " found at position " << i + 1 << endl; 
    }
    else
    {
        cout << "Searched value " << value << " not found" << endl;
    }
}