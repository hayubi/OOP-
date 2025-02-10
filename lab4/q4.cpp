/*TASK # 04
You are building a car rental system. Create a class `Car` to manage cars available for rent.
Requirements:
1. Attributes:
     `carID` (int)
     `model` (string)
     `year` (int)
     `isRented` (bool)
2. Define a default constructor that initializes `isRented` to `false`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
     `rentCar()`: Marks the car as rented.
     `returnCar()`: Marks the car as available.
     `isVintage()`: Returns `true` if the car's year is before 2000.
5. Create a few `Car` objects and test the methods.*/


#include <iostream>
using namespace std;

class Car
{
    private:
        int carID;
        string model;
        int year;
        bool isRented;

    public:
        Car() : isRented(false) {}
        Car(int pID, string pmodel, int pyear, bool prented = false) : carID(pID), model(pmodel), year(pyear), isRented(prented) {}

        void rentCar()
        {
            if (!isRented)
                isRented = true;
        }

        void returnCar()
        {
            if (isRented) 
            {
                isRented = false;
                cout << "Car " << model << " returned. Available now." << endl;
            } 
            else 
                {cout << "Car " << model << " was not rented." << endl;}
        }

        bool isVintage()
        {
            return year < 2000;
        }

        void displayDetails() const 
        {
            cout << "Car ID: " << carID << endl;
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
            cout << "Rental Status: ";
            if (isRented) 
                cout << "Rented" << endl;
            else
                cout << "Available" << endl;
        }
};

int main() 
{
    Car car1(211, "Corolla", 1997);
    Car car2(212, "Sportage", 2019);
    Car car3(213, "Civic", 2006);

    cout << "Initial Car Details:" << endl;
    car1.displayDetails();
    car2.displayDetails();
    car3.displayDetails();
    cout << endl;

    car1.rentCar();
    car2.rentCar();

    cout << "\nRenting Car 2." << endl;
    car2.rentCar();

    cout << "Returning car2 and renting car3." << endl;
    car2.returnCar();
    car3.rentCar();

    cout << "\nIs car1 vintage? ";
    if (car1.isVintage())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Is car2 vintage? ";
    if (car2.isVintage())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Is car3 vintage? ";
    if (car3.isVintage())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "\nFinal Car Details:" << endl;
    car1.displayDetails();
    car2.displayDetails();
    car3.displayDetails();
}
