#include <vector>
#include <algorithm>

using namespace std;

int GetMaxValue(int array[], int size)
{
    int maximum = 0;

    for(int i=0; i<size; i++)
    {
        if(array[i]> maximum)
        {
            maximum = array[i];
        }
    }

    return maximum;
}

void BucketSort(int array[], int size)
{
    int max_element = GetMaxValue(array, size);

    vector<vector<int>> buckets(max_element + 1);

    for (int i = 0; i < size; i++) 
    {
        int index = array[i];
        buckets[index].push_back(array[i]);
    }

    for (int i = 0; i <= max_element; i++) 
    {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int k = 0;

    for (int i = 0; i <= max_element; i++) 
    {
        for (int j = 0; j < buckets[i].size(); j++) 
        {
            array[k++] = buckets[i][j];
        }
    }
}