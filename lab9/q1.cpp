/*Task 01
Problem: A vehicle rental company is expanding its services to include cars, bikes, and
future vehicle types. They need a flexible system to manage daily rates and display vehicle
details without exposing internal calculations. The goal is to ensure new vehicle types (e.g.,
scooters, trucks) can be added seamlessly while maintaining a consistent interface for
customers to view rental options.
Classes and Structure:
• Abstract Class Vehicle:
o Data Members:
▪ model (string): Stores the vehicle’s model name.
▪ rate (double): Stores the daily rental rate.
o Member Functions:
▪ getDailyRate(): Pure virtual function to return the daily rate.
▪ displayDetails(): Pure virtual function to show model and rate.

• Derived Class Car:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide car-specific
behavior.
• Derived Class Bike:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide bike-specific
behavior.

Flow:
• Create Car and Bike objects.
• Use polymorphism to call displayDetails() and getDailyRate() for each vehicle.*/

#include <iostream>
using namespace std;

class Vehicle 
{
    protected:
        string model;
        double rate;

    public:
        Vehicle(const string& m, double r) : model(m), rate(r) {}
        virtual double getDailyRate() const = 0;
        virtual void displayDetails() const = 0;
        virtual ~Vehicle() {}
};

class Car : public Vehicle 
{
    public:
        Car(const string& m, double r) : Vehicle(m, r) {}

        double getDailyRate() const override 
        {
            return rate;
        }

        void displayDetails() const override 
        {
            cout << "Car Model: " << model << ", Daily Rate: $" << getDailyRate() << endl;
        }
};

class Bike : public Vehicle 
{
    public:
        Bike(const string& m, double r) : Vehicle(m, r) {}

        double getDailyRate() const override 
        {
            return rate;
        }

        void displayDetails() const override 
        {
            cout << "Bike Model: " << model << ", Daily Rate: $" << getDailyRate() << endl;
        }
};

int main() 
{
    const int size = 2;
    Vehicle* vehicles[size];

    vehicles[0] = new Car("Honda Civic", 60.0);
    vehicles[1] = new Bike("Royal Enfield", 25.0);

    for (int i=0; i<size; ++i) 
    {
        vehicles[i]->displayDetails();
    }

    for (int i=0; i<size; ++i) 
    {
        delete vehicles[i];
    }
}
