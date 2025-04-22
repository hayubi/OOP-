#include <iostream>
#include <fstream>
using namespace std;

class Student 
{
    public:
        int id;
        string name;
        float gpa;

        void input() {
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "GPA: ";
            cin >> gpa;
        }

        void display() const {
            cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << "\n";
        }

        void writeToFile(ofstream &outFile) const {
            outFile << id << " " << name << " " << gpa << "\n";
        }

        bool readFromFile(ifstream &inFile) 
        {
            inFile >> id >> ws;
            if (!getline(inFile, name, ' ')) return false;
            return (inFile >> gpa);
        }
};

class StudentManager 
{
    public:
        void addInitialStudents() 
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
                s.input();
                s.writeToFile(outFile);
            }

            outFile.close();
        }

        void appendStudent() 
        {
            ofstream outFile("students.txt", ios::app);
            if (!outFile) 
            {
                cerr << "Error opening file for appending.\n";
                return;
            }

            Student s;
            cout << "\nEnter details for additional student:\n";
            s.input();
            s.writeToFile(outFile);

            outFile.close();
        }

        void displayAllStudents() 
        {
            ifstream inFile("students.txt");
            if (!inFile) 
            {
                cerr << "Error opening file for reading.\n";
                return;
            }

            Student s;
            cout << "\nStudent Records:\n";
            while (s.readFromFile(inFile)) 
            {
                s.display();
            }
            inFile.close();
        }
};

int main() 
{
    StudentManager manager;
    manager.addInitialStudents();
    manager.appendStudent();
    manager.displayAllStudents();
}
