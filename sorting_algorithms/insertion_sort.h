using namespace std;

void InsertionSort(int array[], int size) 
{
    int i = 1;
    
    while(i<size)
    {
        int j = i;

        while(j > 0 && array[j-1] > array[j])
        {
            swap(array[j], array[j-1]);
            j = j - 1;
        }
        
        i = i + 1;
    }
}