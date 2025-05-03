#include <iostream>
#include <string>
#include <exception>
using namespace std;

class InsufficientFundsException : public exception 
{
    public:
        virtual const char* what() const noexcept override 
        {
            return "insufficient funds exception";
        }
};

template <typename T>
class BankAccount
{
    private:
        T balance;

    public:
        BankAccount(T bal) 
        {
            balance = bal;
            cout << "Initial Balance: " << balance << endl;
        }

        void withdraw(T amount)
        {
            if (amount > balance)
            {
                cout << "Deficit: " << amount - balance << endl;
                throw InsufficientFundsException();
            }
            balance = balance - amount;
            cout << "Balance: " << balance;
        }
};

int main()
{
    BankAccount<int> b(500);
    int wamt;
    cout << "Enter the amount to withdraw: " << endl;
    cin >> wamt;

    try
    {
        b.withdraw(wamt);
    }
    catch(const exception& e)
    {
        cout << "Withdraw " << wamt << ": " << e.what() << endl;
    }
}
