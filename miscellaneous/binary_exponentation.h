#include <iostream>

using namespace std;

int BinaryExponentationUtil(int a, int b)
{
    int c;

    if(b == 0)
    {
        return 1;
    }

    else if(b%2 != 0)
    {
        c = BinaryExponentationUtil(a, (b-1)/2);
        return a * c * c;
    }

    else
    {
        c = BinaryExponentationUtil(a, b/2);
        return c * c;
    }
}

void BinaryExponentation(int a, int b)
{
    int result = BinaryExponentationUtil(a,b);
    cout << a << "^" << b << " is equal to " << result << endl;
 
}