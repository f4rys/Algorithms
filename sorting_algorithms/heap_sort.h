using namespace std;

void Heapify(int array[], int size, int i)
{
    int maximum = i;
    int left = 2*i + 1;;
    int right = 2*i + 2;

    if(left < size && array[maximum] < array[left])
    {
        maximum = left;
    }

    if(right < size && array[maximum] < array[right])
    {
        maximum = right;
    }  

    if(maximum != i)
    {
        swap(array[i], array[maximum]);
        Heapify(array, size, maximum);
    }
}

void HeapSort(int array[], int size) 
{
    for(int i = size/2-1; i>=0; i--)
    {
        Heapify(array, size, i);
    }

    for(int i=size-1; i>0; i--)
    {
        swap(array[i], array[0]);
        Heapify(array, i, 0);
    }
}