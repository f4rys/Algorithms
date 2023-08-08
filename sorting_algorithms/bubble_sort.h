#include <algorithm>

using namespace std;

void BubbleSort(int array[], int size) 
{
    do
    {
        for(int i = 0; i < size - 1; i++)
        {
            if(array[i] > array[i+1])
            {
                swap(array[i], array[i+1]);
            }
        }
        size--;
    }
    while(size > 1);
}