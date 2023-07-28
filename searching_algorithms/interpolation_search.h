#include <iostream>
using namespace std;

void InterpolationSearch(int array[], int size, int value){

    int left = 0;
    int mid = -1;
    int right = size;

    while(left < right)
    {
        if(left == right || array[left] == array[right])
        {
            break;
        }

        mid = left + ((right - left)/(array[right] - array[left]) * (value - array[left]));

        if(array[mid] == value)
        {
            cout << "Searched value " << value << " found at position " << mid + 1 << endl;
            return;
        }
        else
        {
            if(array[mid] < value)
            {
                left = mid + 1;
            }
            else if(array[mid] > value)
            {
                right = mid - 1;
            }
        }
    }
    
    cout << "Searched value " << value << " not found" << endl;
    return;
}