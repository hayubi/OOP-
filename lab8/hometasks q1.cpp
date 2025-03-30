/*Task# 01
A bank provides different types of accounts, such as Savings Account and Current Account.
Each account has a method to calculate the annual interest, but the formula differs for different
account types.
Additionally, the bank allows overloading the deposit method to handle different types of
deposits (cash, check, online transfer). The withdraw method is overridden to implement specific
rules for different accounts.
Moreover, the bank maintains customer balances in an object, and it supports operator
overloading for addition (+), subtraction (-), multiplication (*), and division (/) to handle
balance calculations efficiently.

Task Requirements:
1. Create a base class BankAccount with attributes like accountNumber, balance, and a
virtual function calculateInterest().
2. Implement two derived classes:
    o SavingsAccount (Interest: 5% per year)
    o CurrentAccount (Interest: No interest)
3. Overload the deposit method in both derived classes to handle:
    o Deposit via cash
    o Deposit via check
    o Deposit via online transfer
4. Override the withdraw method in both derived classes with different rules:
    o SavingsAccount: Cannot withdraw if balance is below $500
    o CurrentAccount: Allows overdraft up to $1000
5. Implement operator overloading in BankAccount:
    o + to add two account balances
    o - to subtract an amount from balance
    o * to apply interest on balance
    o / to calculate equal installment payments from balance
6. Create objects of both SavingsAccount and CurrentAccount, demonstrate method
overloading, overriding, and operator overloading with real transaction examples.*/

#include <iostream>
using namespace std;

class BankAccount 
{
    protected:
        int accountNumber;
        double balance;

    public:
        BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}
        virtual void calculateInterest() = 0;
        
        virtual void withdraw(double amount) 
        {
            if (amount > balance)
                cout << "Insufficient balance!\n";
            else 
            {
                balance = balance - amount;
                cout << "Withdrawn: $" << amount << " New Balance: $" << balance << "\n";
            }
        }
        
        void deposit(double amount) 
        {
            balance = balance + amount;
            cout << "Deposited: $" << amount << " New Balance: $" << balance << "\n";
        }
        
        void deposit(double amount, string type) 
        {
            cout << "Depositing via " << type << "\n";
            deposit(amount);
        }
        
        double getBalance() const { return balance; }
        
        virtual BankAccount* operator+(const BankAccount &other) const = 0;
        virtual BankAccount* operator-(double amount) const = 0;
        virtual BankAccount* operator*(double interestRate) const = 0;
        virtual BankAccount* operator/(int installments) const = 0;
        
        void displayBalance() const
        {
            cout << "Account Number: " << accountNumber << " Balance: $" << balance << "\n";
        }
};

class SavingsAccount : public BankAccount 
{
    public:
        SavingsAccount(int accNum, double bal) : BankAccount(accNum, bal) {}
        
        void calculateInterest() override 
        {
            balance = balance * 1.05;
            cout << "Annual Interest Applied. New Balance: $" << balance << "\n";
        }
        
        void withdraw(double amount) override 
        {
            if (balance - amount < 500)
                cout << "Cannot withdraw. Minimum balance of $500 required.\n";
            else
                BankAccount::withdraw(amount);
        }
        
        SavingsAccount* operator+(const BankAccount &other) const override
        {
            return new SavingsAccount(accountNumber, balance + other.getBalance());
        }
        
        SavingsAccount* operator-(double amount) const override
        {
            return new SavingsAccount(accountNumber, balance - amount);
        }
        
        SavingsAccount* operator*(double interestRate) const override
        {
            return new SavingsAccount(accountNumber, balance * (1 + interestRate / 100));
        }
        
        SavingsAccount* operator/(int installments) const override
        {
            return new SavingsAccount(accountNumber, balance / installments);
        }
};

class CurrentAccount : public BankAccount 
{
    public:
        CurrentAccount(int accNum, double bal) : BankAccount(accNum, bal) {}
        
        void calculateInterest() override 
        {
            cout << "No interest for Current Accounts.\n";
        }
        
        void withdraw(double amount) override 
        {
            if (balance - amount < -1000)
                cout << "Overdraft limit exceeded!\n";
            else
                BankAccount::withdraw(amount);
        }
        
        CurrentAccount* operator+(const BankAccount &other) const override
        {
            return new CurrentAccount(accountNumber, balance + other.getBalance());
        }
        
        CurrentAccount* operator-(double amount) const override
        {
            return new CurrentAccount(accountNumber, balance - amount);
        }
        
        CurrentAccount* operator*(double interestRate) const override
        {
            return new CurrentAccount(accountNumber, balance * (1 + interestRate / 100));
        }
        
        CurrentAccount* operator/(int installments) const override
        {
            return new CurrentAccount(accountNumber, balance / installments);
        }
};

int main() 
{
    SavingsAccount sa(101, 1000);
    CurrentAccount ca(102, 500);
    
    sa.deposit(200, "cash");
    ca.deposit(300, "online transfer");
    
    sa.withdraw(600);
    ca.withdraw(1200);
    
    sa.calculateInterest();
    ca.calculateInterest();
    
    BankAccount* totalBalance = sa + ca;
    totalBalance->displayBalance();
    delete totalBalance;
    
    BankAccount* newSa = sa * 5;
    newSa->displayBalance();
    delete newSa;
    
    BankAccount* newCa = ca - 100;
    newCa->displayBalance();
    delete newCa;
}