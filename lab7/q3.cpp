/*Task 03 
Envision creating a robust application for a global finance firm that needs to handle and compute multiple currencies with real-time conversion capabilities. This system is built on a base class called Currency, which contains core data members such as amount, currencyCode, currencySymbol, and an optional exchangeRate. It provides functions like convertToBase() for converting the amount into a common base currency, convertTo(targetCurrency) for converting between currencies, and displayCurrency() for showcasing currency details. 
Derived classes like Dollar, Euro, and Rupee extend this foundation by introducing currency- specific details and overriding convertToBase() and displayCurrency() to reflect the exchange rates and regional currency formats dynamically. 
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Currency
{
    protected:
        double amount;
        string currencyCode;
        string currencySymbol;
        double exchangeRate;

    public:
        Currency(double amt, string code, string symbol, double rate = 1.0) : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

        virtual double convertToBase() const
        {
            return amount * exchangeRate;
        }

        virtual double convertTo(const Currency &targetCurrency) const
        {
            double baseAmount = convertToBase();
            return baseAmount / targetCurrency.exchangeRate;
        }

        virtual void displayCurrency() const
        {
            cout << currencySymbol << " " << fixed << setprecision(2) << amount
                << " (" << currencyCode << ")" << endl;
        }
};

class Dollar : public Currency
{
    public:
        Dollar(double amt) : Currency(amt, "USD", "$") {}

        double convertToBase() const override
        {
            return amount;
        }

        void displayCurrency() const override
        {
            cout << currencySymbol << " " << fixed << setprecision(2) << amount
                << " (" << currencyCode << ") - Dollar" << endl;
        }
};

class Euro : public Currency
{
    public:
        Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

        double convertToBase() const override
        {
            return amount * exchangeRate;
        }

        void displayCurrency() const override
        {
            cout << currencySymbol << " " << fixed << setprecision(2) << amount
                << " (" << currencyCode << ") - Euro" << endl;
        }
};

class Rupee : public Currency
{
    public:
        Rupee(double amt) : Currency(amt, "INR", "₹", 0.013) {}

        double convertToBase() const override
        {
            return amount * exchangeRate;
        }

        void displayCurrency() const override
        {
            cout << currencySymbol << " " << fixed << setprecision(2) << amount
                << " (" << currencyCode << ") - Rupee" << endl;
        }
};

int main()
{
    Dollar usd(100);
    Euro eur(100);
    Rupee inr(1000);

    cout << "Original Currencies:" << endl;
    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();

    double convertedEurToUsd = eur.convertTo(usd);
    cout << "\nConverted 100 EUR to USD: $" << fixed << setprecision(2) << convertedEurToUsd << endl;

    double convertedInrToEur = inr.convertTo(eur);
    cout << "Converted 1000 INR to EUR: €" << fixed << setprecision(2) << convertedInrToEur << endl;

    double convertedUsdToInr = usd.convertTo(inr);
    cout << "Converted 100 USD to INR: ₹" << fixed << setprecision(2) << convertedUsdToInr << endl;
}
