/*Task-03:
Create a class called ValidateString. The purpose of this class will be check if the given characters in a
string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a
parameterized constructor, create multiple objects for your class that accept different strings. Create a
constant function that checks whether the string variable is valid or not.
What happens if you do not make your function constant? Add a comment right above your function
explaining why we make a function constant.*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class ValidateString
{
    private:   
        string word;

    public:
        ValidateString(string w) : word(w) {}

        bool checkAlphabets() const
        {
            for (char c: word)
            {
                if (!( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ))
                {
                    return false;
                }
            }
            return true;
        }

        void print() const
        {
            if (checkAlphabets())
                cout << "String '" << word << "' is valid" << endl;
            else
                cout << "String '" << word << "' is not valid" << endl;
        }
};


int main()
{
    ValidateString w1("oops");
    ValidateString w2("oops123");
    ValidateString w3("oops@#");

    w1.print();
    w2.print();
    w3.print();
}