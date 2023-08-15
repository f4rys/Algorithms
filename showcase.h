#include <iostream>

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

#include "dynamic_programming/coin_change_problem.h"
#include "dynamic_programming/fibonacci_series.h"
#include "dynamic_programming/knapsack_problem.h"
#include "dynamic_programming/longest_increasing_subsequence.h"

#include "miscellanous/binary_exponentation.h"
#include "miscellanous/extended_euclidean_algorithm.h"
#include "miscellanous/josephus_problem.h"
#include "miscellanous/majority_voting_algorithm.h"
#include "miscellanous/sieve_of_eratosthenes.h"

using namespace std;

void ShowcaseMiscellanousAlgorithms(){

    // Binary exponentation variables
    int base = 3;
    int power = 6;

    // Extended Euclidean Algorithm variables
    int a = 35; 
    int b = 15;

    // Josephus Problem variables
    int n = 8;
    int k = 3;

    // Majority Voting Algorithm variables
    const int count = 8;
    int array[count] = {1, 5, 3, 1, 1, 1, 1, 2};

    // Sieve of Eratosthenes variables
    int range_end = 59;

    cout << "Binary exponentation:" << endl;
    BinaryExponentation(base, power);
    cout << endl;

    cout << "Extended Euclidean algorithm:" << endl;
    ExtendedEuclideanAlgorithm(a,b);
    cout << endl;

    cout << "Josephus problem:" << endl;
    JosephusProblem(n,k);
    cout << endl;

    cout << "Majority voting algorithm:" << endl;
    MajorityVotingAlgorithm(array, count);
    cout << endl;

    cout << "Sieve of Eratosthenes:" << endl;
    SieveOfEratosthenes(range_end);
    cout << endl;

}

void ShowcaseDynamicProgrammingAlgorithms(){

    // Coin change problem variables
    int coins_sum = 4;
    const int COINS_COUNT = 3;
    int coins[COINS_COUNT] = {1, 2, 3};

    // Fibonacci series variables
    const int FIBONACCI = 10;

    // Knapsack problem variables
    const int ITEM_COUNT = 4;
    const int KNAPSACK_CAPACITY = 10;
    int values[ITEM_COUNT] = {10, 40, 30, 50};
    int weights[ITEM_COUNT] = {5, 4, 6, 3};

    // Longest increasing subsequence variables
    const int LENGTH = 8;
    int array[LENGTH] = {10, 22, 9, 33, 21, 50, 41, 60};

    cout << "Coin change problem solved with dynamic programming:" << endl;
    CoinChangeProblem(coins, COINS_COUNT, coins_sum);
    cout << endl;

    cout << "Fibonacci series using dynamic programming:" << endl;
    FibonacciSeries(FIBONACCI);
    cout << endl;

    cout << "Knapsack problem using dynamic programming:" << endl;
    KnapsackProblem(ITEM_COUNT, KNAPSACK_CAPACITY, values, weights);
    cout << endl;

    cout << "Longest increasing subsequence using dynamic programming:" << endl;
    LongestIncreasingSubsequence(array, LENGTH);
    cout << endl;
}

void ShowcaseStringAlgorithms(){
    const int SIZE = 3;
    string array[SIZE] = {"mango", "manhattan", "manmade"};
    string str = "razzmatazz";
    string pattern = "zz";

    cout << "Knuth-Morris-Pratt pattern searching algorithm:" << endl;
    PatternSearching(str, pattern);
    cout << endl;

    cout << "Longest common prefix using Divide and Conquer approach:" << endl;
    LongestCommonPrefix(array, SIZE);
    cout << endl;

    cout << "Longest palindromic substring using naive approach:" << endl;
    LongestPalindromicSubstring(array, SIZE);
    cout << endl;
}

void ShowcaseSearchingAlgorithms(){

    const int SIZE = 500;
    int array[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        array[i] = i + 1;
    }

    int value = 465;

    cout << "Linear search:" << endl;
    MeasureTimeOfSearchingAlgorithms(array, SIZE, value, &LinearSearch);
    
    cout << "Binary search:" << endl;
    MeasureTimeOfSearchingAlgorithms(array, SIZE, value, &BinarySearch);

    cout << "Interpolation search:" << endl;
    MeasureTimeOfSearchingAlgorithms(array, SIZE, value, &InterpolationSearch);

    cout << "Jump search:" << endl;
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
    MeasureTimeOfSortingAlgorithms(array, SIZE, &BubbleSort);

    cout << "Bucket sort:" << endl;
    MeasureTimeOfSortingAlgorithms(array, SIZE, &BucketSort);

    cout << "Heap sort:" << endl;
    MeasureTimeOfSortingAlgorithms(array, SIZE, &HeapSort);

    cout << "Insertion sort:" << endl;
    MeasureTimeOfSortingAlgorithms(array, SIZE, &InsertionSort);

    cout << "Merge sort:" << endl;
    MeasureTimeOfSortingAlgorithms(array, SIZE, &MergeSort);

    cout << "Quick sort:" << endl;
    MeasureTimeOfSortingAlgorithms(array, SIZE, &QuickSort);

    cout << "Selection sort:" << endl;
    MeasureTimeOfSortingAlgorithms(array, SIZE, &SelectionSort);
}