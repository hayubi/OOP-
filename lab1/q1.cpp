/*Q1: Write a C++ program to check whether a given number is prime or not. Allow the user to input a number and display whether it's prime or not?*/

#include <iostream>
using namespace std;
int main()
{
    int num;
    bool isPrime = true;

    cout << "Enter a number: ";
    cin >> num;

    if (num <= 1)
        {isPrime= false;}
    else 
    {
        for (int i=2; i<num; i++)
        {
            if (num%2 == 0)
            {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime == true)
        cout << num << " is a prime number" << endl;
    else 
        cout << num << " is not a prime number" << endl;

    return 0;
}