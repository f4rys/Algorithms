using namespace std;

int GetMinimalValue(int array[], int i, int size)
{
    int minimal = array[i];
    int position = i;

    for(int j=i+1; j<size; j++)
    {
        if(minimal > array[j])
        {
            minimal = array[j];
            position = j;
        }
    }

    return position;
}

void SelectionSort(int array[], int size) 
{
    for(int i=0; i<size; i++)
    {
        int position = GetMinimalValue(array, i, size);
        
        swap(array[i], array[position]);
    }
}