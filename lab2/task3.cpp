/*Task 3) Write a C++ program that:
• Dynamically allocates a 2D array using pointers (not using vector or standard containers).
• Fills the array with random integers between 1 and 100.
• Pass the 2D array to function to perform these tasks:
• Calculates and prints The sum of all elements in the array.
• Calculates and prints The sum of each row and each column.
• Calculates and prints The row and column with the highest sum.
• Pass the 2D array to a function to transpose the matrix and print the resulting matrix.
Free the dynamically allocated memory.
Note: Use functions to perform the calculations and matrix operations (do not write all code inside main() ). Handle edge cases, such as when the array has no elements or is improperly allocated.
Sample Output:
Original Matrix:
[ 12 35 56 ]
[ 8 45 67 ]
[ 23 54 34 ]
Sum of all elements: 434
Row sums: 103, 120, 111
Column sums: 43, 134, 157
Row with highest sum: Row 2
Column with highest sum: Column 3
Transposed Matrix:
[ 12 8 23 ]
[ 35 45 54 ]
[ 56 67 34 ]
*/

#include <iostream>
using namespace std;
int main()