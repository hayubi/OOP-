/*Q2. A user wishes to update their resume in your Resume Builder application.
Requirements:
1.⁠ ⁠Prompt the user to enter:
    ○ string name
    ○ string email
    ○ int yearsOfExperience
    ○ string summary
Write this data to a file called resume.txt.
Use ofstream with ios::trunc to ensure that any previous contents are completely
deleted before writing new data.
After writing, read back and display the contents to confirm that the file only has the
latest entry. use whatever appropriate*/

#include <iostream>
#include <fstream>
using namespace std;

class Resume 
{
    private:
        string name;
        string email;
        int yearsOfExperience;
        string summary;

    public:
        void input() 
        {
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your email: ";
            getline(cin, email);
            cout << "Enter your years of experience: ";
            cin >> yearsOfExperience;
            cin.ignore();
            cout << "Enter a brief summary: ";
            getline(cin, summary);
        }

        void writeToFile(const string& filename) 
        {
            ofstream outFile(filename, ios::trunc);
            if (!outFile) 
            {
                cerr << "Error opening file for writing.\n";
                return;
            }

            outFile << "Name: " << name << "\n";
            outFile << "Email: " << email << "\n";
            outFile << "Years of Experience: " << yearsOfExperience << "\n";
            outFile << "Summary: " << summary << "\n";

            outFile.close();
        }

        void displayFromFile(const string& filename) 
        {
            ifstream inFile(filename);
            if (!inFile) 
            {
                cerr << "Error opening file for reading.\n";
                return;
            }

            cout << "\nResume Contents:\n";
            string line;
            while (getline(inFile, line)) 
            {
                cout << line << "\n";
            }

            inFile.close();
        }
};

int main() 
{
    Resume r;
    r.input();
    r.writeToFile("resume.txt");
    r.displayFromFile("resume.txt");
}
