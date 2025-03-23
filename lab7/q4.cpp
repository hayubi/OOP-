/*Task 04 
Imagine designing a digital management system for a large university that seamlessly integrates academic and administrative operations. At the heart of this system is a Person class that stores universal data members such as name, id, address, phone Number, and email. It provides functions like displayInfo() to show personal details and updateInfo() to modify them. 
Derived classes-Student, Professor, and Staff-extend this system by introducing specific data members: 
• Student includes courses Enrolled, GPA, and enrollmentYear, modifying displayInfo() to show academic records. 
• Professor has department, courses Taught, and salary, updating displayInfo() to display faculty-specific details. 
• Staff maintains department, position, and salary, tailoring displayInfo() to reflect administrative roles. 
An additional Course class, with attributes like courseld, courseName, credits, instructor, and schedule, provides functions such as registerStudent(student) and calculateGrades(). This ensures an interactive system where function overrides enable dynamic role-based 
management. 
*/

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() const
    {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address
             << "\nPhone Number: " << phoneNumber << "\nEmail: " << email << endl;
    }

    void updateInfo(string newName, string newId, string newAddress, string newPhone, string newEmail)
    {
        name = newName;
        id = newId;
        address = newAddress;
        phoneNumber = newPhone;
        email = newEmail;
    }

    // Getter for name to make it accessible
    string getName() const
    {
        return name;
    }
};

class Student : public Person
{
private:
    string coursesEnrolled[5];
    double GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string addr, string phone, string mail, double gpa, int year)
        : Person(n, i, addr, phone, mail), GPA(gpa), enrollmentYear(year) {}

    void addCourse(string course, int index)
    {
        if (index >= 0 && index < 5)
        {
            coursesEnrolled[index] = course;
        }
    }

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Courses Enrolled: ";
        for (int i = 0; i < 5 && !coursesEnrolled[i].empty(); ++i)
        {
            cout << coursesEnrolled[i] << " ";
        }
        cout << "\nGPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person
{
private:
    string department;
    string coursesTaught[3];
    double salary;

public:
    Professor(string n, string i, string addr, string phone, string mail, string dept, double sal)
        : Person(n, i, addr, phone, mail), department(dept), salary(sal) {}

    void addCourse(string course, int index)
    {
        if (index >= 0 && index < 3)
        {
            coursesTaught[index] = course;
        }
    }

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Department: " << department << "\nCourses Taught: ";
        for (int i = 0; i < 3 && !coursesTaught[i].empty(); ++i)
        {
            cout << coursesTaught[i] << " ";
        }
        cout << "\nSalary: Rs. " << salary << endl;
    }
};

class Staff : public Person
{
private:
    string department;
    string position;
    double salary;

public:
    Staff(string n, string i, string addr, string phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: Rs. " << salary << endl;
    }
};

class Course
{
private:
    string courseId;
    string courseName;
    int credits;
    Professor *instructor;
    string schedule;
    string enrolledStudents[5];

public:
    Course(string id, string name, int credit, Professor *prof, string sched)
        : courseId(id), courseName(name), credits(credit), instructor(prof), schedule(sched) {}

    void registerStudent(string studentName, int index)
    {
        if (index >= 0 && index < 5)
        {
            enrolledStudents[index] = studentName;
        }
    }

    void calculateGrades()
    {
        cout << "Calculating grades for " << courseName << endl;
    }

    void displayCourseInfo() const
    {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName
             << "\nCredits: " << credits << "\nInstructor: " << instructor->getName()
             << "\nSchedule: " << schedule << endl;
        cout << "Enrolled Students: ";
        for (int i = 0; i < 5 && !enrolledStudents[i].empty(); ++i)
        {
            cout << enrolledStudents[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Professor prof1("Dr. Ahmed Khan", "P001", "Karachi, Sindh", "0300-1234567", "ahmed.khan@university.edu.pk", "Computer Science", 120000);
    Student student1("Ali Raza", "S101", "Lahore, Punjab", "0321-2345678", "ali.raza@student.edu.pk", 3.8, 2020);
    Student student2("Sania Malik", "S102", "Islamabad", "0333-8765432", "sania.malik@student.edu.pk", 3.6, 2021);

    prof1.addCourse("CS101", 0);
    prof1.addCourse("CS201", 1);

    student1.addCourse("CS101", 0);
    student1.addCourse("CS201", 1);

    Course cs101("CS101", "Introduction to Programming", 3, &prof1, "Mon/Wed 10:00 AM - 12:00 PM");
    cs101.registerStudent("Ali Raza", 0);
    cs101.registerStudent("Sania Malik", 1);

    cout << "Professor Information:\n";
    prof1.displayInfo();
    cout << "\nStudent 1 Information:\n";
    student1.displayInfo();
    cout << "\nStudent 2 Information:\n";
    student2.displayInfo();
    cout << "\nCourse Information:\n";
    cs101.displayCourseInfo();

    cs101.calculateGrades();
}

