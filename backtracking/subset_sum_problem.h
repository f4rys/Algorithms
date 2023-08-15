#include <iostream>
using namespace std;

void SubsetSumProblemSolver(int i, int n, int set[], int target_sum, int* subset, int& count)
{
    if (target_sum == 0) 
    {
        count++;

        cout << "Solution " << count << ": {";

        bool is_last_element = true;

        for (int j = 0; j < n; j++) 
        {
            if (subset[j] != 0) 
            {
                if (!is_last_element) 
                {
                    cout << ", ";
                }

                cout << subset[j];
                is_last_element = false;
            }
        }

        cout << "}" << endl;

        return;
    }

    if (i == n || target_sum < 0) 
    {
        return;
    }

    subset[i] = set[i];
    SubsetSumProblemSolver(i + 1, n, set, target_sum - set[i], subset, count);
    subset[i] = 0;

    SubsetSumProblemSolver(i + 1, n, set, target_sum, subset, count);
}

void SubsetSumProblem(int set[], int sum, int N)
{
    cout << "Target sum is " << sum <<  " and the set is: {";

    for(int i=0; i<N; i++)
    {
        cout << set[i];

        if(i != N-1)
        {
            cout << ", ";
        }
    }

    cout << "}" << endl;

    int* subset = new int[N]();
    int count = 0;

    SubsetSumProblemSolver(0, N, set, sum, subset, count);

    delete[] subset;
}