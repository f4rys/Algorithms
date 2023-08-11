#include <iostream>
#include <windows.h>

#include "measure_time.h"

#include "sorting_algorithms/bubble_sort.h"
#include "sorting_algorithms/bucket_sort.h"
#include "sorting_algorithms/heap_sort.h"
#include "sorting_algorithms/insertion_sort.h"
#include "sorting_algorithms/merge_sort.h"
#include "sorting_algorithms/quick_sort.h"
#include "sorting_algorithms/selection_sort.h"

#include "searching_algorithms/linear_search.h"
#include "searching_algorithms/binary_search.h"
#include "searching_algorithms/interpolation_search.h"
#include "searching_algorithms/jump_search.h"

#include "string_algorithms/pattern_searching.h"
#include "string_algorithms/longest_common_prefix.h"
#include "string_algorithms/longest_palindromic_substring.h"

using namespace std;

void ShowcaseStringAlgorithms(){
    const int SIZE = 3;
    string array[SIZE] = {"mango", "manhattan", "manmade"};
    string str = "razzmatazz";
    string pattern = "zz";

    cout << "Knuth-Morris-Pratt pattern searching algorithm:" << endl;
    Sleep(1000);
    MeasureTimeOfKMPAlgorithm(str, pattern, &PatternSearching);

    cout << "Longest common prefix using Divide and Conquer approach:" << endl;
    Sleep(1000);
    MeasureTimeOfStringAlgorithms(array, SIZE, &LongestCommonPrefix);

    cout << "Longest palindromic substring using naive approach:" << endl;
    Sleep(1000);
    MeasureTimeOfStringAlgorithms(array, SIZE, &LongestPalindromicSubstring);
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

void ShowcaseSortingAlgorithms(){

    const int SIZE = 100;
    int array[SIZE] = {41, 44, 68, 66, 93, 90, 67, 18, 85, 71, 87, 83,	83,	41,	76, 54,	75,	90,	47,	59,
                        27,	61,	37,	90,	39, 37,	54,	86,	54,	67, 71, 85,	20,	23,	18, 54,	72,	40,	75,	94,
                        19,	38,	35,	94,	59, 33,	68,	97,	4,	40, 25, 93,	9,	16,	81, 51, 74,	99,	98,	29,
                        10,	45,	22,	90,	73, 58,	49,	85,	33,	74, 75, 68,	31,	92,	48, 62, 96, 91,	37,	98, 
                        26,	34,	28,	20,	12, 88, 34,	20,	22,	98, 96,	5, 93, 15, 85, 77, 50, 68, 27, 26};
    
    cout << "Bubble sort:" << endl;
    Sleep(1000);
    MeasureTimeOfSortingAlgorithms(array, SIZE, &BubbleSort);

    cout << "Bucket sort:" << endl;
    Sleep(1000);
    MeasureTimeOfSortingAlgorithms(array, SIZE, &BucketSort);

    cout << "Heap sort:" << endl;
    Sleep(1000);
    MeasureTimeOfSortingAlgorithms(array, SIZE, &HeapSort);

    cout << "Insertion sort:" << endl;
    Sleep(1000);
    MeasureTimeOfSortingAlgorithms(array, SIZE, &InsertionSort);

    cout << "Merge sort:" << endl;
    Sleep(1000);
    MeasureTimeOfSortingAlgorithms(array, SIZE, &MergeSort);

    cout << "Quick sort:" << endl;
    Sleep(1000);
    MeasureTimeOfSortingAlgorithms(array, SIZE, &QuickSort);

    cout << "Selection sort:" << endl;
    Sleep(1000);
    MeasureTimeOfSortingAlgorithms(array, SIZE, &SelectionSort);
}