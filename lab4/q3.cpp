/*TASK # 03
You are building a bank account management system. Create a class `Account` to manage bank
accounts.
Requirements:
1. Attributes:
     `accountNumber` (string)
     `accountHolderName` (string)
     `balance` (double)
2. Define a default constructor that initializes `balance` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
     `deposit(double amount)`: Adds the amount to the balance.
     `withdraw(double amount)`: Deducts the amount from the balance (if sufficient funds are
    available).
     `checkBalance()`: Displays the current balance.
5. Create a few `Account` objects and test the methods.*/


#include <iostream>
#include <string>
using namespace std;

class Account 
{
    private:
        string accnum;
        string accHolderName;
        double balance;
    
    public:
        Account() : balance(0.0) {}
        Account(string pAccNum, string pHolderName, double pBalance) : accnum(pAccNum), accHolderName(pHolderName), balance(pBalance) {}

        void deposit(double amount)
        {
            if (amount > 0)
            {
                balance = balance + amount;
                cout << amount << " deposited successfully from Account " << accnum << endl;
            }
            else 
                cout << "Invalid amount of Account " << accnum << endl;
        }

        void withDraw(double amount)
        {
            if (balance >= amount && amount > 0)
            {
                balance = balance - amount;
                cout << amount << " withdrew successfully from Account " << accnum << endl;
            }
            else
                cout << "Insuficient balance of Account " << accnum << endl;
        }

        void checkBalance() const
        {
            cout << "Current Balance of Account " << accnum << ": " << balance << endl;
        }

        void displayAccountDetails()
        {
            cout << "Account Number: " << accnum << endl;
            cout << "Account Holder: " << accHolderName << endl;
            cout << "Balance: " << balance << endl;
        }
};

int main()
{
    Account acc1("P0846", "Umna", 850.5);
    Account acc2("P4522", "Marium", 999.9);
    
    cout << "\nAccount 1 Details:\n";
    acc1.displayAccountDetails();
    cout << "\nAccount 2 Details:\n";
    acc2.displayAccountDetails();

    cout << endl;
    acc1.deposit(500);
    acc2.withDraw(300);
    cout << endl;
    acc1.checkBalance();
    acc2.checkBalance();
    cout << endl;
    acc2.withDraw(1300);
}