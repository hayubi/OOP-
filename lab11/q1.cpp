#include <iostream>
using namespace std;

class InvalidValueException : public exception
{
    public:
        InvalidValueException() {}

        const char* what() const noexcept override
        {
            return "invalid age";
        }
};

void ValidateAge(int age)
{
    if (age < 0 || age > 120)
    {
        throw InvalidValueException(); //throwing an instance of InvalidValueException
    }
}

int main()
{
    int age;
    cout << "ente the age: " << endl;
    cin >> age;
    try
    {
        ValidateAge(age);
        cout << "Age is " << age << endl;
    }
    catch(const exception& e)
    {
        cout << "Exception occurred: " << e.what() << endl;
    }
}
