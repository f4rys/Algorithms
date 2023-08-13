#include <iostream>
#include <vector>

using namespace std;

// Fibonacci Series using dynamic programming and top-down approach
int FibonacciSeries(int N, vector<int>& array){
    if(N == 0 || N == 1){
        return N;
    }
    if(array[N] != 0){
        return array[N];
    }
    array[N] = FibonacciSeries(N-1, array) + FibonacciSeries(N-2, array);
    return array[N];
}

void FibonacciSeries(int N){
    vector<int> array(N + 1, 0);
    cout << "Element at the index " << N << " in the Fibonacci Sequence is " << FibonacciSeries(N, array) << "." << endl;
}