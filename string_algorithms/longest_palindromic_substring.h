#include <iostream>
#include <string>

using namespace std;

// Longest palindromic substring using naive approach
void LongestPalindromicSubstring(string str) 
{   
    int length = str.length();
    int max_length = 1;
    int start = 0;

    for(int i = 0; i < length; i++) 
    {
        for(int j = i; j < length; j++) 
        {
            bool flag = 1;
            
            for(int k = 0; k < (j-i+1)/2; k++) 
            {
                if(str[i+k] != str[j-k])
                {
                    flag = 0;
                    break;
                }
            }

            if(flag && (j-i+1) > max_length) 
            {
                start = i;
                max_length = j-i+1;
            }
        }
    }

    cout << "Longest palindromic substring a of string '" << str << "' is '";

    for(int i = start; i < start + max_length; i++) 
    {
        cout << str[i];
    }

    cout << "'"<< endl;
}

void LongestPalindromicSubstring(string array[], int size)
{
    for(int i=0; i<size; i++)
    {
        LongestPalindromicSubstring(array[i]);
    }
}