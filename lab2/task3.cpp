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
#include <cstdlib>
#include <ctime>
using namespace std;

void fillMatrix(int** matrix, int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);
int sumElements(int** matrix, int rows, int cols);
void rowSum(int** matrix, int rows, int cols);
void columnSum(int** matrix, int rows, int cols);
void findMaxRowColumn(int** matrix, int rows, int cols);
void transposeMatrix(int** matrix, int rows, int cols);
void freeMemory(int** matrix, int rows);

int main() 
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int*[rows];
    for (int i=0; i<rows; i++) 
    {
        matrix[i] = new int[cols];
    }

    fillMatrix(matrix, rows, cols);
    cout << endl;
    cout << "Original Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    cout << endl;
    cout << "Sum of all elements: " << sumElements(matrix, rows, cols) << endl;
    rowSum(matrix, rows, cols);
    columnSum(matrix, rows, cols);
    findMaxRowColumn(matrix, rows, cols);

    cout << endl;
    cout << "Transposed Matrix:" << endl;
    transposeMatrix(matrix, rows, cols);

    freeMemory(matrix, rows);
}

void fillMatrix(int** matrix, int rows, int cols) 
{
    srand(time(0));
    for (int i=0; i<rows; i++) 
    {
        for (int j=0; j<cols; j++) 
        {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) 
{
    for (int i=0; i<rows; i++) 
    {
        for (int j=0; j<cols; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int sumElements(int** matrix, int rows, int cols) 
{
    int sum=0;
    for (int i=0; i<rows; i++) 
    {
        for (int j=0; j<cols; j++) 
        {
            sum = sum + matrix[i][j];
        }
    }
    return sum;
}

void rowSum(int** matrix, int rows, int cols) 
{
    for (int i=0; i<rows; i++) 
    {
        int rowsum=0;
        for (int j=0; j<cols; j++) 
        {
            rowsum = rowsum + matrix[i][j];
        }
        cout << "Row " << i+1 << ": " << rowsum << endl;
    }
}

void columnSum(int** matrix, int rows, int cols) 
{
    for (int j=0; j<cols; j++) 
    {
        int colsum=0;
        for (int i=0; i<rows; i++) 
        {
            colsum = colsum + matrix[i][j];
        }
        cout << "Column " << j+1 << ": " << colsum << endl;
    }
}

void findMaxRowColumn(int** matrix, int rows, int cols) 
{
    int maxRowSum=0, maxRowIndex=0, maxColSum=0, maxColIndex=0;

    for (int i=0; i<rows; i++) 
    {
        int rowsum=0;
        for (int j=0; j<cols; j++) 
        {
            rowsum = rowsum + matrix[i][j];
        }
        if (rowsum > maxRowSum) 
        {
            maxRowSum = rowsum;
            maxRowIndex = i;
        }
    }

    for (int j=0; j<cols; j++) 
    {
        int colsum=0;
        for (int i=0; i<rows; i++) 
        {
            colsum = colsum + matrix[i][j];
        }
        if (colsum > maxColSum) 
        {
            maxColSum = colsum;
            maxColIndex = j;
        }
    }
    
    cout << endl;
    cout << "Row with highest sum: Row " << maxRowIndex+1 << endl;
    cout << "Column with highest sum: Column " << maxColIndex+1 << endl;
}

void transposeMatrix(int** matrix, int rows, int cols) 
{
    int** transposed = new int*[cols];
    for (int i=0; i<cols; i++) 
    {
        transposed[i] = new int[rows];
    }

    for (int i=0; i<rows; i++) 
    {
        for (int j=0; j<cols; j++) 
        {
            transposed[j][i] = matrix[i][j];
        }
    }

    for (int i=0; i<cols; i++) 
    {
        for (int j=0; j<rows; j++) 
        {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=0; i<cols; i++) 
    {
        delete[] transposed[i];
    }
    delete[] transposed;
}

void freeMemory(int** matrix, int rows) 
{
    for (int i=0; i<rows; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}