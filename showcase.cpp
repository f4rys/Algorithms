#include <iostream>
#include <chrono>
#include <windows.h> 

#include "searching_algorithms/linear_search.h"
#include "searching_algorithms/binary_search.h"
#include "searching_algorithms/interpolation_search.h"
#include "searching_algorithms/jump_search.h"

using namespace std;
using namespace std::chrono;
 
void MeasureTimeOfSearchingAlgorithms(int array[], int size, int value, void (*functionPtr)(int*, int, int)) {
    auto start = high_resolution_clock::now();
    functionPtr(array, size, value);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Runtime: " << duration.count() << " microseconds" << endl << endl;
}

void ShowcaseSearchingAlgorithms(){

    const int SIZE = 500;
    int array[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        array[i] = i + 1;
    }

    int value = 465;

    cout << "Linear search:" << endl;
    Sleep(1000);
    MeasureTimeOfSearchingAlgorithms(array, SIZE, value, &LinearSearch);
    
    cout << "Binary search:" << endl;
    Sleep(1000);
    MeasureTimeOfSearchingAlgorithms(array, SIZE, value, &BinarySearch);

    cout << "Interpolation search:" << endl;
    Sleep(1000);
    MeasureTimeOfSearchingAlgorithms(array, SIZE, value, &InterpolationSearch);

    cout << "Jump search:" << endl;
    Sleep(1000);
    MeasureTimeOfSearchingAlgorithms(array, SIZE, value, &JumpSearch);

}

int main() {

    ShowcaseSearchingAlgorithms();

    return 0;
}
