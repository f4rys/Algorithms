#include <chrono>
#include <windows.h> 
#include <iostream>

using namespace std;
using namespace std::chrono;

void MeasureTimeOfSearchingAlgorithms(int array[], int size, int value, void (*functionPtr)(int*, int, int)) {
    auto start = high_resolution_clock::now();
    functionPtr(array, size, value);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Runtime: " << duration.count() << " microseconds" << endl << endl;
}
