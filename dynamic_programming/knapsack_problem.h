#include <iostream>
#include <algorithm>

using namespace std;

void KnapsackProblem(int n, int w, int values[], int weights[]){
    
    int** matrix = new int*[n+1];

    for (int i = 0; i < n+1; i++) {
        matrix[i] = new int[w+1];
    }

    for(int i=0; i<w; i++){
        matrix[0][i] = 0;
    }

    for(int i=0; i<n; i++){
        matrix[i][0];
    }

    for(int item=1; item<=n; item++){
        for(int capacity = 1; capacity<=w; capacity++){
            int maxValWithoutCurrent = matrix[item-1][capacity];
            int maxValWithCurrent = 0;
            int weightOfCurrent = weights[item-1];

            if(capacity >= weightOfCurrent){
                maxValWithCurrent = values[item -1];

                int remainingCapacity = capacity - weightOfCurrent;
                maxValWithCurrent += matrix[item-1][remainingCapacity];
            }

            matrix[item][capacity] = max(maxValWithCurrent, maxValWithoutCurrent);
        }
    }

    cout << "Knapsack has capacity equal to " << w << ".";
    cout << " There are " << n << " items with values {";

    for(int i=0; i<n; i++)
    {
        cout << values[i];
        if(i != n-1){
            cout << ", ";
        }
    }

    cout << "} and corresponding weights {";

    for(int i=0; i<n; i++)
    {
        cout << weights[i];
        if(i != n-1){
            cout << ", ";
        }
    }

    cout << "}." << endl;

    cout << "Greatest value of items that can be fit in the knapsack is " << matrix[n][w] << "." << endl;

    for (int i = 0; i < n+1; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}