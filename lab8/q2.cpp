#include <iostream>
using namespace std;

class Account
{
    private:
        string accountNumber, accountHolder;
        double balance;

    public:
        Account(string number, string holder, double bal) : accountNumber(number), accountHolder(holder), balance(bal) {}

        Account operator+(const Account &acc) const 
        { 
            return Account("", "", balance + acc.balance); 
        }

        Account& operator-(double amount) 
        { 
            balance = balance - amount; 
            return *this; 
        }

        bool operator>(const Account &acc) const 
        { 
            return balance > acc.balance; 
        }

        friend ostream& operator<<(ostream &out, const Account &acc) 
        {
            out << "Account Number: " << acc.accountNumber << " | Holder: " << acc.accountHolder << " | Balance: $" << acc.balance;
            return out;
        }

        double getBalance() const { return balance; }
        void setBalance(double newBalance) { balance = newBalance; }
};

int main() 
{
    Account acc1("101", "Shafique Rehman", 5000);
    Account acc2("102", "Talha", 3000);
    
    Account totalBalance = acc1 + acc2;
    cout << "Total Balance (After Addition): " << totalBalance.getBalance() << "\n\n";
    
    acc1 = acc1 - 2000;
    acc2.setBalance(acc2.getBalance() + 2000);
    cout << "After Transfer:\n";
    cout << "Shafique Rehman's New Balance: " << acc1.getBalance() << "\n";
    cout << "Talha's New Balance: " << acc2.getBalance() << "\n\n";
    
    cout << "Comparison:\n";
    if (acc1 > acc2)
        cout << "Shafique Rehman has more balance than Talha.\n\n";
    else
        cout << "Shafique Rehman has less balance than Talha.\n\n";
    
    cout << "Final Account Details:\n";
    cout << acc1 << "\n";
    cout << acc2 << "\n";
}
