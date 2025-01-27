/*Task 2) Write a C++ program that:
    • Reads n strings from the user and stores them in a dynamically allocated array of char*.
    • Prints the strings in reverse order using pointer arithmetic.
    • Finds and prints the string with the most vowels (a, e, i, o, u).
    • Calculates and prints the average length of all the strings.
    Note: Use pointer notation wherever possible.
If there are multiple strings with the same number of vowels, print the first one encountered
*/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    char **strArray = new char*[n];
    int *strLengths = new int[n];
    int *vowelCount = new int[n];

    for (int i=0; i<n; i++) 
        {vowelCount[i] = 0;}

    for (int i=0; i<n; i++) 
    {
        cout << "Enter string " << i+1 << ": ";
        strArray[i] = new char[100];  
        cin >> strArray[i]; 
        strLengths[i] = strlen(strArray[i]); 
    }
    
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<strLengths[i]; j++) 
        {
            if (*(strArray[i] + j) == 'a' || *(strArray[i] + j) == 'e' || *(strArray[i] + j) == 'i' || *(strArray[i] + j) == 'o' || *(strArray[i] + j) == 'u') 
                {vowelCount[i]++;}
        }
    }

    int maxVowels = -1;
    int index;
    for (int i=0; i<n; i++) 
    {
        if (vowelCount[i] > maxVowels) 
        {
            maxVowels = vowelCount[i];
            index = i;
        }
    }
    cout << endl;
    cout << "String with max vowels(" << vowelCount[index] << "): " << strArray[index] << endl;

    int avgLength = 0;
    for (int i=0; i<n; i++) 
    {
        avgLength = avgLength + strLengths[i];
    }
    avgLength = avgLength/n;
    cout << "Average length is " << avgLength << endl;

    cout << endl;
    cout << "Strings in reverse order: " << endl;
    for (int i=0; i<n; i++) 
    {
        for (int j=strLengths[i]-1; j>= 0; j--) 
        {
            cout << *(strArray[i] + j);
        }
        cout << "\n";
    }

    for (int i=0; i<n; i++) 
    {
        delete[] strArray[i];
    }
    delete[] strArray;
    delete[] strLengths;
    delete[] vowelCount;
}
