#include <cmath>

using namespace std;

void BinarySearch(int array[], int size, int value)
{
    int left = 0;
    int right = size - 1;

    while(left <= right)
    {
        int mean = floor((left+right)/2);

        if(array[mean] < value)
        {
            left = mean + 1;
        }
        else if(array[mean] > value)
        {
            right = mean - 1;
        }
        else
        {
            cout << "Searched value " << value << " found at position " << mean + 1 << endl;
            return;
        }
    }
    
    cout << "Searched value " << value << " not found" << endl;
}