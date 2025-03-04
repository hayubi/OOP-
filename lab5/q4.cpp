/*Task-04:
Create a BankAccount class. Which contains following details and functionalties:
Attributes: The BankAccount class has three private member variables: accountNumber,
accountHolderName, and balance.
Create Constructor: The class has a constructor that takes parameters to initialize the account
details (accountNumber, accountHolderName, and balance).
Create following Member Functions:
• deposit(double amount): Adds the specified amount to the account balance.
• withdraw(double amount): Subtracts the specified amount from the account balance, if
sufficient funds are available.
• display(): Displays the account details including the account number, account holder name,
and balance.
In the main() function, create an array accounts of BankAccount objects. The array contains three
elements, each representing a different bank account.
Initialize Each BankAccount object with specific account details such as account number, holder
name, and initial balance.
Perform following operations:
• Iterate through each account in the accounts array.
• For each account, display the account details using the display() function.
• Perform Two Transactions:
• Deposits 500.0 rupees into the account.
• Withdraws 200.0 rupees from the account.
• After each transaction, display the updated account details, including the new balance.*/


#include <iostream>
#include <string>
using namespace std;

class BankAccount 
{
    private:
        int accountNumber;
        string accountHolderName;
        double balance;

    public:
        BankAccount(int accnum, string name, double bal) : accountNumber(accnum), accountHolderName(name), balance(bal) {}

        void deposit(double amount) 
        {
            if (amount > 0) 
            {
                balance = balance + amount;
                cout << "Deposited Rs." << amount << " New balance: Rs." << balance << endl;
            } 
            else 
                cout << "Invalid deposit amount" << endl;
        }

        void withdraw(double amount) 
        {
            if (amount > 0 && amount <= balance) 
            {
                balance = balance - amount;
                cout << "Withdrew Rs." << amount << " New balance: Rs." << balance << endl;
            } 
            else if (amount > balance) 
                cout << "Insufficient balance to withdraw Rs." << amount << endl;
            else 
                cout << "Invalid withdrawal amount" << endl;
        }

        void display() 
        {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holder Name: " << accountHolderName << endl;
            cout << "Current Balance: Rs." << balance << endl;
        }
};

int main() 
{
    BankAccount accounts[] = 
    {
        BankAccount(112, "Asra", 1700.0),
        BankAccount(113, "Umna", 2000.0),
        BankAccount(114, "Zara", 2500.0)
    };

    for (int i=0; i<3; i++) 
    {
        cout << "\n--Account " << (i+1) << " details--" << endl;
        accounts[i].display();
        cout << endl;
        accounts[i].deposit(500.0);
        accounts[i].withdraw(200.0);
        cout << endl << "Updated Details:" << endl;
        accounts[i].display();
    }
}
