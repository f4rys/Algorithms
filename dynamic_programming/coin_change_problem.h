#include <iostream>

using namespace std;

void CoinChangeProblem(int coins[], int n, int sum) {
    int i, j;

    int** array = new int*[sum + 1];

    for (i = 0; i <= sum; i++) {
        array[i] = new int[n + 1];
    }

    for (i = 0; i <= sum; i++) {
        for (j = 0; j <= n; j++) {
            array[i][j] = 0;
        }
    }

    for (i = 0; i <= n; i++) {
        array[0][i] = 1;
    }

    for (i = 1; i <= sum; i++) {
        for (j = 1; j <= n; j++) {
            array[i][j] = array[i][j - 1];

            if (i - coins[j-1] >= 0) {
                array[i][j] += array[i - coins[j-1]][j];
            }
        }
    }

    cout << "Available coins are {";

    for(int i=0; i<n; i++)
    {
        cout << coins[i];
        if(i != n-1){
            cout << ", ";
        }
    }

    cout << "}. We want to know how many ways there are to pay the price equal to " << sum << "." << endl;

    cout << "There are " << array[sum][n] << " solutions to coin change problem." << endl;

    for (i = 0; i <= sum; i++) {
        delete[] array[i];
    }

    delete[] array;
}