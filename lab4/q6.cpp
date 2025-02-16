/*TASK # 06
Scenario: A bank wants to develop a system for managing customer accounts. The system
should allow customers to:
1. Create a new account with an account number, owner’s name, and initial balance
    (default balance is 0 if not provided).
2. Deposit money into their account.
3. Withdraw money from their account, ensuring they cannot withdraw more than the
    available balance.
4. Display account details including account number, owner’s name, and current balance.
Your task is to implement a C++ program that fulfills these requirements.*/

#include <iostream>
#include <string>
using namespace std;

class Account 
{
    private:
        string accnum;
        string ownername;
        double iBalance;

    public:
        Account() : iBalance(0.0) {}

        Account(string pAccNum, string pName, double pbalance = 0.0) : accnum(pAccNum), ownername(pName), iBalance(pbalance) {}

        void deposit(double amount) 
        {
            if (amount > 0) 
            {
                iBalance = iBalance + amount;
                cout << amount << "$ succeessfully deposited" << endl;
            }
            else
                cout << "Invalid amount." << endl;
        }

        void withdraw(double amount) 
        {
            if (iBalance >= amount) 
            {
                iBalance = iBalance - amount;
                cout << amount << "$ succeessfully withdrew" << endl;
            } 
            else 
                cout << "Insufficient balance." << endl;
        }

        void displayAccountDetails() const 
        {
            cout << "Account Number: " << accnum << endl;
            cout << "Account Owner: " << ownername << endl;
            cout << "Current Balance: $" << iBalance << endl;
        }
};

int main() 
{
    string accNum, name;
    double initialBalance, depositAmount, withdrawAmount;
    int choice;

    Account customer1;
    cout << "Enter account number: ";
    cin >> accNum;
    cin.ignore();
    cout << "Enter account holder's name: ";
    getline(cin, name);
    cout << "Enter initial balance: ";
    cin >> initialBalance;
    customer1 = Account(accNum, name, initialBalance);


    do 
    {
        cout << "\n--- Bank Account System ---" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Display Account Details" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> depositAmount;
                customer1.deposit(depositAmount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> withdrawAmount;
                customer1.withdraw(withdrawAmount);
                break;

            case 3:
                customer1.displayAccountDetails();
                break;

            case 4:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}