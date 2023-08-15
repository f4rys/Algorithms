#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void SieveOfEratosthenes(int n)
{
    int last_index = -1;
    vector<bool> primes(n+1, true);

    for(int i=2; i<=sqrt(n); i++)
    {
        if(primes[i])
        {
            for(int j=i*i; j<=n; j=j+i)
            {
                primes[j] = false;
            }
        }
    }

    cout << "Prime numbers from 2 to " << n << " are: {";
    
    for (int i = 2; i <= n; i++) 
    {
        if (primes[i])
        {
            if (last_index != -1) 
            {
                cout << ", ";
            }

            cout << i;
            last_index = i;
        }
    }

    cout << "}" << endl;
}