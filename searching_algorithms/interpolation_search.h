using namespace std;

void InterpolationSearch(int array[], int size, int value){
    
    int left = 0;
    int mid = -1;
    int right = size - 1;

    while(left <= right)
    {
        if(array[left] == array[right])
        {
            if (array[left] == value) {
                cout << "Searched value " << value << " found at position " << left + 1 << endl;
                return;
            } else {
                cout << "Searched value " << value << " not found" << endl;
                return;
            }
        }

        mid = left + ((double)(value - array[left]) / (array[right] - array[left])) * (right - left);

        if(mid < 0 || mid >= size)
        {
            cout << "Searched value " << value << " not found" << endl;
            return;
        }

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
}
