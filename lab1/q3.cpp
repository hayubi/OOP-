/*Q3: Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may
not use the same element twice.You can return the answer in any order.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].*/

#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    
    int array[size];
    cout << "Enter " << size << " numbers:" << endl;
    for (int i=0; i<size; i++)
    {
        cin >> array[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    int index1, index2;
    bool isFound = false;
    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (array[i] + array[j] == target)
            {
                isFound = true;
                index1 = i;
                index2 = j;
            }
        }
    }

    if (isFound)
        cout << "[" << index1 << "," << index2 << "]";
    else
        cout << "Sum cannot be found from the given array elements.";
}