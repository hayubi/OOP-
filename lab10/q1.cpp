/*Q1. You are building a student record management tool for a university system.
Requirements:
1.⁠ ⁠Define a structure Student with the following fields:
    ○ int id
    ○ string name
    ○ float gpa
Prompt the user to enter data for 5 students.
Write these records to a file named students.txt using ofstream with ios::out
mode.
Then, allow the user to append 1 additional student record using ios::app mode
(open in append mode and write without erasing old content).
Finally, read and display all student records from the file using ifstream.*/

#include <iostream>
#include <fstream>
using namespace std;

struct Student 
{
    int id;
    string name;
    float gpa;
};

void writeInitialRecords() 
{
    ofstream outFile("students.txt", ios::out);
    if (!outFile) 
    {
        cerr << "Error opening file for writing.\n";
        return;
    }

    Student s;
    for (int i=0; i<5; ++i) 
    {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> s.id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, s.name);
        cout << "GPA: ";
        cin >> s.gpa;

        outFile << s.id << " " << s.name << " " << s.gpa << "\n";
    }
    outFile.close();
}

void appendStudentRecord() 
{
    ofstream outFile("students.txt", ios::app);
    if (!outFile) 
    {
        cerr << "Error opening file for appending.\n";
        return;
    }

    Student s;
    cout << "\nEnter details for additional student:\n";
    cout << "ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Name: ";
    getline(cin, s.name);
    cout << "GPA: ";
    cin >> s.gpa;

    outFile << s.id << " " << s.name << " " << s.gpa << "\n";
    outFile.close();
}

void displayRecords() 
{
    ifstream inFile("students.txt");
    if (!inFile) 
    {
        cerr << "Error opening file for reading.\n";
        return;
    }

    Student s;
    cout << "\nStudent Records:\n";
    while (inFile >> s.id >> ws && getline(inFile, s.name, ' ') && inFile >> s.gpa) 
    {
        cout << "ID: " << s.id << ", Name: " << s.name << ", GPA: " << s.gpa << "\n";
    }

    inFile.close();
}

int main() 
{
    writeInitialRecords();
    appendStudentRecord();
    displayRecords();
}
