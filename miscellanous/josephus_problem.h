#include <iostream>

using namespace std;

void JosephusProblem(int n, int k)
{
    int i = 1;
    int result = 0;

    while(i <= n)
    {
        result = (result + k) % i;
        i++;
    }

    cout << "The answer for Josephus problem for n=" << n << " and k=" << k << " is " << result + 1 << endl;
}