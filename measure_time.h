#include <chrono>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void MeasureTimeOfKMPAlgorithm(string str, string pattern, void (*functionPtr)(string, string)){
    auto start = steady_clock::now();
    functionPtr(str, pattern);
    auto stop = steady_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Runtime: " << duration.count() << " microseconds" << endl << endl;
}

void MeasureTimeOfStringAlgorithms(string array[], int size, void (*functionPtr)(string*, int))
{
    auto start = steady_clock::now();
    functionPtr(array, size);
    auto stop = steady_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Runtime: " << duration.count() << " microseconds" << endl << endl;
}

void MeasureTimeOfSearchingAlgorithms(int array[], int size, int value, void (*functionPtr)(int*, int, int)) {
    auto start = steady_clock::now();
    functionPtr(array, size, value);
    auto stop = steady_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Runtime: " << duration.count() << " microseconds" << endl << endl;
}

void MeasureTimeOfSortingAlgorithms(int array[], int size, void (*functionPtr)(int*, int)){
    int* temp_array = new int[size];

    for (int i = 0; i < size; i++) {
        temp_array[i] = array[i];
    }

    auto start = steady_clock::now();
    functionPtr(temp_array, size);
    auto stop = steady_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Runtime: " << duration.count() << " microseconds" << endl << endl;

    delete[] temp_array;
}
