using namespace std;

void MergeArrays(int array[], int left, int mean, int right)
{
    int leftSize = mean - left + 1;
    int rightSize = right - mean;

    int *leftArray = new int[leftSize];
    int *rightArray = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = array[left + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        rightArray[j] = array[mean + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void MergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mean = (left + right) / 2;
        MergeSort(array, left, mean);
        MergeSort(array, mean + 1, right);
        MergeArrays(array, left, mean, right);
    }
}

void MergeSort(int array[], int size)
{
    int left = 0;
    int right = size - 1;
    MergeSort(array, left, right);
}