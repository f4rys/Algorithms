#include <iostream>
#include <algorithm>

using namespace std;

void LongestIncreasingSubsequence(int array[], int size){

    int* lis = new int[size];

    lis[0] = 1;

    for(int i=1; i<size; i++){
        for(int j=0; j<i; j++){
            if(array[i]> array[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    }

    int maximum = 0;

    for(int i=0; i<size; i++){
        maximum = max(maximum, lis[i]);
    }

    cout << "Longest increasing subsequence in array {";

    for(int i=0; i<size; i++){
        cout << array[i];
        if(i!=size-1){
            cout << ", ";
        }

    }
    
    cout << "} is of length " << maximum << "." << endl;

    delete[] lis;
}