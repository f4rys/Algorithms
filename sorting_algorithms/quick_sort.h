#include <algorithm>

using namespace std;

int DivideArrays(int array[], int left, int right)
{
    int division_index = (left + right) / 2;
    int division_value = array[division_index];

    swap(array[division_index], array[right]);

    int position = left;

    for(int i = left; i <= right; i++)
    {
        if(array[i] < division_value)
        {
            swap(array[i], array[position]);
            position++;
        }
    }

    swap(array[position], array[right]);
    return position;
}

void QuickSort(int array[], int left, int right)
{
    if(left < right)
    {
        int i = DivideArrays(array, left, right);

        QuickSort(array, left, i-1);
        QuickSort(array, i+1, right);
    }
}

void QuickSort(int array[], int size) 
{
    int left = 0;
    int right = size - 1;
    
    QuickSort(array, left, right);
}