#include <iostream>
#include <string>

using namespace std;

// Pattern searching using KMP algorithm
void ComputeLPSArray(string pattern, int M, int lps[])
{
    int len = 0;
    lps[0] = 0;

    int i = 1;

    while(i < M)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            if(len != 0)
            {
                len = lps[len-1];
            }

            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void PatternSearching(string str, string pattern)
{
    int N = str.length();
    int M = pattern.length();

    int* lps = new int[M]();

    ComputeLPSArray(pattern, M, lps);

    int i = 0;
    int j = 0;

    bool flag = 0;

    while ((N - i) >= (M - j)) 
    {
        if(pattern[j] == str[i])
        {
            i++;
            j++;
        }

        if(j == M)
        {
            cout << "Pattern " << pattern << " found at index " << i - j << " in a string '" << str << "'" << endl;
            flag = 1;
            j = lps[j-1];
        }

        else if(i < N && pattern[j] != str[i])
        {
            if(j != 0)
            {
                j = lps[j-1];
            }

            else
            {
                i++;
            }
        }
    }

    if(j == M)
    {
        cout << "Pattern '" << pattern << "' found at index " << i - j << " in a string '" << str << "'" << endl;
        flag = 1;
    }

    else if(flag == 0)
    {
        cout << "Pattern '" << pattern << "' not found in a string '" << str << "'" << endl;
    }

    delete[] lps;
}