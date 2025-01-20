/*Q2: Design a C++ program to manage student marks. Allow the user to input
marks for students in three subjects (Mathematics, English, and Science). The
program should calculate the total marks, average marks, and display the grade
for each student. The user can specify the number of students and then input
the marks for each subject for each student. Finally, display the marks, total,
average, and grade for each student. Assume a grading system with the
following criteria:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F*/

#include <iostream>
using namespace std;
int main()
{
    int numofstudents;
    cout << "Enter number of students: ";
    cin >> numofstudents;
    int array[numofstudents][3];
    for (int i=0; i<numofstudents; i++)
    {
        cout << "Student " << i+1 << ":" << endl;
        cout << "Mathematics: ";
        cin >> array[i][0];
        cout << "English: ";
        cin >> array[i][1];
        cout << "Science: ";
        cin >> array[i][2];

        int total = array[i][0] + array[i][1] + array[i][2];
        cout << "Total: " << total << endl;
        float average = ((array[i][0] + array[i][1] + array[i][2])/3.0);
        cout << "Average: " << average << endl;
        if (average >= 90)
            cout << "Grade: A";
        else if (average >= 80 && average <= 89)
            cout << "Grade: B";
        else if (average >= 70 && average <= 79)
            cout << "Grade: C";
        else if (average >= 60 && average <= 69)
            cout << "Grade: D";
        else 
            cout << "Grade: F";
        cout << endl;
    }
}