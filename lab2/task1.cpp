/*Task 1) Write a C++ program that reads a group of n numbers from the user and stores them in a dynamically
allocated array of type float. Then, the program should:
    • Calculate the average of the numbers.
    • Find the number closest to the average.
    • Print the average and the number closest to it.
    • Use pointer notation wherever possible.
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    float *numbers = new float[n];
    cout << "Enter " << n << " numbers: " << endl;
    for (int i=0; i<n; i++)
    {
        cin >> *(numbers + i);
    }

    float sum=0;
    for (int i=0; i<n; i++)
    {
        sum = sum + *(numbers + i);
    }
    float average = sum/n;
    cout << "Average: " << average << endl;

    float closest;
    float minDiff = -1;
    for (int i=0; i<n; i++)
    {
        float difference = *(numbers+i) - average;
        if (difference < 0)
            {difference = -difference;}
        
        if (difference < minDiff || minDiff == -1)
        {
            minDiff = difference;
            closest = *(numbers + i); 
        }
    }
    cout << "The number closest to average is: " << closest;
    
    delete []numbers;
}