/*Task 04
Problem: An e-commerce platform aims to support multiple payment methods (credit
cards, digital wallets) to attract global customers. The payment system must validate
transactions securely and allow new payment options (e.g., cryptocurrency) to be added
without rewriting existing code.
Classes and Structure:
• Abstract Class PaymentMethod:
o Member Function:
▪ processPayment(double amount): Pure virtual function to handle
transactions.
• Derived Class CreditCard:
o Data Members:
▪ cardNumber (string): Stores the card number.
o Implements processPayment() to validate and process payments.
• Derived Class DigitalWallet:
o Data Members:
▪ balance (double): Tracks available funds.
o Implements processPayment() to deduct balance.

Flow:
• Create CreditCard and DigitalWallet objects.
• Simulate payments and check for success/failure.*/

#include <iostream>
#include <string>
using namespace std;

class PaymentMethod 
{
    public:
        virtual bool processPayment(double amount) = 0;
        virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod 
{
    private:
        string cardNumber;

    public:
        CreditCard(const string& number) : cardNumber(number) {}

        bool processPayment(double amount) override 
        {
            cout << "Processing credit card payment of $" << amount << " using card: " << cardNumber << endl;
            return true;
        }
};

class DigitalWallet : public PaymentMethod 
{
    private:
        double balance;

    public:
        DigitalWallet(double initialBalance) : balance(initialBalance) {}

        bool processPayment(double amount) override 
        {
            if (balance >= amount) 
            {
                balance = balance - amount;
                cout << "Digital Wallet Payment of $" << amount << " processed successfully.\n";
                return true;
            } 
            else 
            {
                cout << "Insufficient balance.\n";
                return false;
            }
        }
};

int main()
{
    CreditCard card("1234-5678-9012-3456");
    DigitalWallet wallet(100.0);
    card.processPayment(50.0);
    wallet.processPayment(60.0);
    wallet.processPayment(50.0);
}
