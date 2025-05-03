#include <iostream>
#include <cmath>
#include <string>
#include <typeinfo>
using namespace std;

class NegativeNumberException : public exception
{
    public:
        const char* what() const noexcept override
        {
            return "NegativeNumberException - Input must be non-negative!";
        }
};

class InvalidTypeException : public exception
{
    public:
        const char* what() const noexcept override 
            {
                return "InvalidTypeException - Non-numeric type detected!";
            }
};

template <typename T>
void sqroot(T num)
{
    if (num < 0)
        { throw NegativeNumberException(); }
    else if (typeid(num) != typeid(int) && typeid(num) != typeid(float))
        { throw InvalidTypeException(); }
    else
        { cout << "Sqr root: " << pow(num, 0.5) << endl; }
}


int main()
{
    int num;
    cout << "Enter number to calulate square root: ";
    cin >> num;
    try
    {
        sqroot(num);
    }
    catch(const NegativeNumberException& e)
    {
        cout << "Negative Number Exception: " << e.what() << endl;
    }
    catch(const InvalidTypeException& e)
    {
        cout << "Invalid Type Exception: " << e.what() << endl;
    }
}
