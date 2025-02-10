/*TASK # 01
You are building a student management system. Create a class `Student` to manage student records.
Requirements:
1. Attributes:
     `studentID` (int)
     `name` (string)
     `age` (int)
     `grade` (char)
2. Define a default constructor that initializes `grade` to `'N'` (Not Assigned).
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
     `promoteStudent()`: Upgrades the student's grade (e.g., from 'B' to 'A').
     `isEligibleForScholarship()`: Returns `true` if the student's grade is 'A'.
     `displayDetails()`: Displays the student's details.
5. Create a few `Student` objects and test the methods.*/

#include <iostream>
using namespace std;

class Student
{
    private:
        int studentID;
        string name;
        int age;
        char grade;

    public:
        Student() : grade('N') {} //default constructor
        Student(int pID, string pname, int page, char pgrade) : studentID(pID), name(pname), age(page), grade(pgrade) {} //parameterised constructor

        void promoteStudent()
        {
            if (grade > 'A' && grade <= 'D')
                {grade--;}
        }

        bool isEligibleForScholarship()
        {
            if (grade == 'A')
                {return true;}
            else 
                {return false;}
        }

        void displayDetails()
        {
            cout << "ID: " << studentID << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Grade: " << grade << endl;

            if (isEligibleForScholarship())
                {cout << name << " is eligible for scholarship." << endl;}
            else
                {cout << name << " is not eligible for scholarship." << endl;}
        }
};

int main()
{
    Student s1(846, "Umna", 21, 'A');
    Student s2(884, "Mishal", 19, 'C');
    Student s3(854, "Abeer", 20, 'B');
    Student s4(878, "Asra", 22, 'D');

    cout << "Student Details: " << endl;
    cout << endl;
    cout << "---Before Promotion---" << endl;
    s1.displayDetails(); cout << endl;
    s2.displayDetails(); cout << endl;
    s3.displayDetails(); cout << endl;
    s4.displayDetails(); cout << endl;

    cout << "---After Promotion---" << endl;
    s1.promoteStudent();
    s2.promoteStudent();
    s3.promoteStudent();
    s4.promoteStudent();
    s1.displayDetails(); cout << endl;
    s2.displayDetails(); cout << endl;
    s3.displayDetails(); cout << endl;
    s4.displayDetails(); cout << endl;
}