#include <iostream>
#include <cmath>
#include <exception>
#include <string>
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
T sqrtTemplate(T num) 
{
    if constexpr (!(is_same<T, int>::value || is_same<T, float>::value || is_same<T, double>::value))
        throw InvalidTypeException();
    if (num < 0)
        throw NegativeNumberException();
        
    return sqrt(num);
}

int main() 
{
    try 
    {
        cout << "Result: " << sqrtTemplate(-4) << endl;
    }
    catch (const exception& e) 
    {
        cout << "sqrt(-4): " << e.what() << endl;
    }

    try 
    {
        cout << "Result: " << sqrtTemplate(string("hello")) << endl;
    }
    catch (const exception& e) 
    {
        cout << "sqrt(\"hello\"): " << e.what() << endl;
    }
}
