/*TASK # 05
You are building an employee management system. Create a class `Employee` to manage employee
records.
Requirements:
    1. Attributes:
     `employeeID` (int)
     `name` (string)
     `department` (string)
     `salary` (double)
2. Define a default constructor that initializes `salary` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
     `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
     `isManager()`: Returns `true` if the employee's department is "Management".
     `displayDetails()`: Displays the employee's details.
5. Create a few `Employee` objects and test the methods.*/


#include <iostream>
#include <string>
using namespace std;

class Employee 
{
    private:
        int employeeID;
        string name;
        string department;
        double salary;

    public:
        Employee() : salary(0.0) {}

        Employee(int pid, string pName, string pDept, double pSalary) : employeeID(pid), name(pName), department(pDept), salary(pSalary) {}

        void giveBonus(double amount) 
        {
            salary = salary + amount;
        }

        bool isManager() 
        {
            if (department == "Management")
                return true;
            return false;
        }

        void displayDetails() 
        {
            cout << "\nID: " << employeeID << endl;
            cout << "Name: " << name << endl;
            cout << "Department: " << department << endl;
            cout << "Salary: " << salary << endl;
        }
};

int main() 
{
    Employee emp1(121, "Manahil", "HR", 78000);
    Employee emp2(122, "Armeen", "Management", 55600);
    Employee emp3(123, "Marium", "Sales", 36000);
    emp1.displayDetails();
    emp2.displayDetails();
    emp3.displayDetails();

    cout << "\nBonus of 8000$ given to employee 2" << endl;
    emp2.giveBonus(8000);
    emp2.displayDetails();

    cout << "\nIs emp2 a manager? ";
    if (emp2.isManager())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Is emp3 a manager? ";
    if (emp3.isManager())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

}