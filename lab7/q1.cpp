/*Task 01 
Imagine developing a comprehensive banking system simulator for a prominent financial institution. In this system, a base class called Account encapsulates essential data members such as accountNumber, balance, accountHolderName, and optionally accountType. It offers member functions like deposit(amount) to add funds, withdraw(amount) to remove funds with proper error checking, calculateInterest() to compute interest based on varying rules, printStatement() to output detailed transaction histories, and getAccountInfo() to retrieve general account details. 
Derived classes like Savings Account, CheckingAccount, and Fixed DepositAccount extend this structure by incorporating specialized data members-such as interestRate and minimumBalance for Savings Account or maturity Date and fixedInterestRate for Fixed DepositAccount. These derived classes override key functions like calculateInterest() and printStatement() to provide account-type-specific functionalities. Additionally, the withdraw() function is overridden in specific accounts to apply different transaction rules, ensuring that each account type follows realistic banking policies while maintaining polymorphic behavior. 
*/

#include <iostream>
using namespace std;

class Account 
{
    protected:
        int accountNumber;
        double balance;
        string accountHolderName;
        string accountType;

    public:
        Account(int accNum, double bal, string name, string type) : accountNumber(accNum), balance(bal), accountHolderName(name), accountType(type) {}

        virtual void deposit(double amount) 
        {
            balance = balance + amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
        }

        virtual void withdraw(double amount) 
        {
            if (amount > balance)
                cout << "Insufficient balance!" << endl;
            else 
            {
                balance = balance - amount;
                cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
            }
        }

        virtual void calculateInterest() = 0;

        virtual void printStatement() const 
        {
            cout << "Account Number: " << accountNumber << "\nHolder: " << accountHolderName
                << "\nBalance: " << balance << "\nType: " << accountType << "\n";
        }
};

class SavingsAccount : public Account 
{
    private:
        double interestRate;
        double minimumBalance;

    public:
        SavingsAccount(int accNum, double bal, string name, double rate, double minBal) : Account(accNum, bal, name, "Savings"), interestRate(rate), minimumBalance(minBal) {}

        void calculateInterest() override 
        {
            double interest = balance * (interestRate/100);
            balance = balance + interest;
            cout << "Interest added: " << interest << "\nNew balance: " << balance << endl;
        }

        void withdraw(double amount) override 
        {
            if (balance - amount < minimumBalance) 
                cout << "Cannot withdraw! Minimum balance requirement not met." << endl;
            else
                Account::withdraw(amount);
        }
};

class CheckingAccount : public Account 
{
    private:
        double transactionFee;

    public:
        CheckingAccount(int accNum, double bal, string name, double fee) : Account(accNum, bal, name, "Checking"), transactionFee(fee) {}

        void withdraw(double amount) override 
        {
            if (amount + transactionFee > balance)
                cout << "Insufficient balance after transaction fee!" << endl;
            else 
            {
                balance = balance - (amount + transactionFee);
                cout << "Withdrawn " << amount << " (Fee: " << transactionFee << "). New balance: " << balance << endl;
            }
        }

        void calculateInterest() override 
        {
            cout << "Checking accounts do not earn interest." << endl;
        }
};

class FixedDepositAccount : public Account 
{
    private:
        double fixedInterestRate;
        int maturityPeriod;

    public:
        FixedDepositAccount(int accNum, double bal, string name, double rate, int period) : Account(accNum, bal, name, "Fixed Deposit"), fixedInterestRate(rate), maturityPeriod(period) {}

        void calculateInterest() override 
        {
            double interest = balance * (fixedInterestRate/100) * (maturityPeriod/12.0);
            cout << "Interest earned after " << maturityPeriod << " months: " << interest << endl;
        }

        void withdraw(double amount) override 
        {
            cout << "Withdrawal not allowed before maturity!" << endl;
        }
};

int main() 
{
    SavingsAccount s(1001, 5000, "Alice", 5.0, 1000);
    CheckingAccount c(1002, 3000, "Bob", 10);
    FixedDepositAccount f(1003, 10000, "Charlie", 6.0, 12);

    cout << "\n--Savings Account Operations--\n";
    s.deposit(1000);
    s.withdraw(4500);
    s.calculateInterest();
    s.printStatement();

    cout << "\n--Checking Account Operations--\n";
    c.deposit(500);
    c.withdraw(2500);
    c.calculateInterest();
    c.printStatement();

    cout << "\n--Fixed Deposit Account Operations--\n";
    f.deposit(2000);
    f.withdraw(5000);
    f.calculateInterest();
    f.printStatement();
}