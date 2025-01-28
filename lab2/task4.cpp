/*Task 4) You are required to write a C++ program that will create a function named unique that will take array
as input. the array may contain the duplicate values but you have to process on the array and have to
return the array which must contains only unique values not duplicates.
Example: 
Size of array: 7
Elements of array: [5, 2, 5, 3, 2, 1, 8]
Unique elements: 5 2 3 1 8 
*/

#include <iostream>
using namespace std;

int unique(int array[], int size, int result[]) 
{
    int rSize = 0;
    for (int i=0; i<size; i++) 
    {
        bool duplicate = false;
        for (int j=0; j<rSize; j++) 
        {
            if (array[i] == result[j]) 
            {
                duplicate = true;
                break;
            }
        }
        
        if (!duplicate) 
        {
            result[rSize] = array[i];
            rSize++;
        }
    }
    return rSize;
}

int main() 
{
    int size ;
    cout << "Enter the size of array: ";
    cin >> size;
    int *array = new int[size];
    cout<<"Enter the elements: " << endl;
    for (int i=0; i<size; i++)
    {
        cin >> array[i];
    }
    int *result = new int[size];
    
    int uniqueSize = unique(array, size, result);
    
    cout << "Unique elements: ";
    for (int i=0; i<uniqueSize; i++) 
        {cout << result[i] << " ";}
    cout << endl;
}
