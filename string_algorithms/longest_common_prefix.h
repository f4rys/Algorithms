#include <iostream>
#include <string>

using namespace std;

//Longest common prefix using Divide and Conquer approach
string CommonPrefixUtil(string str1, string str2)
{
    string result;
    int size1 = str1.length();
    int size2 = str2.length();
    int i = 0, j = 0;

    while(i <= size1-1 && j <= size2-1)
    {
        if(str1[i] != str2[j])
        {
            break;
        }

        result += str1[i];
        i++;
        j++;
    }

    return result;
}

string LongestCommonPrefix(string array[], int left, int right)
{   
    if(left == right)
    {
        return array[left];
    }

    if(left < right)
    {
        int mid = (left + right) / 2;
        string str1 = LongestCommonPrefix(array, left, mid);
        string str2 = LongestCommonPrefix(array, mid + 1, right);

        return CommonPrefixUtil(str1, str2);
    }

    return "";
}

void LongestCommonPrefix(string array[], int size)
{   
    int left = 0;
    int right = size - 1;
    string result = LongestCommonPrefix(array, left, right);

    cout << "Longest common prefix in array of strings: '";

    for(int i=0; i<size; i++)
    {
        cout << array[i];
        if(i != size-1){
            cout << ", ";
        }
        
    }
    
    cout << "' is '" << result << "'" << endl;
}