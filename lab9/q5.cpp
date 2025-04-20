/*Task 05
Problem: A fitness app wants to help users track calories burned during activities like
running and cycling. Each activity requires unique calculations (e.g., distance vs. speed), but
the app must present results consistently. The system should allow adding new activities
(e.g., swimming) in the future.
Classes and Structure:
• Abstract Class Activity:
o Member Function:
▪ calculateCaloriesBurned(): Pure virtual function to compute calories.

• Derived Class Running:
o Data Members:
▪ distance (double): Stores distance in kilometers.
▪ time (double): Stores duration in minutes.
o Implements calculateCaloriesBurned() for running.
• Derived Class Cycling:

o Data Members:
▪ speed (double): Stores speed in km/h.
▪ time (double): Stores duration in hours.
o Implements calculateCaloriesBurned() for cycling.

Flow:
• Create Running and Cycling objects.
• Display calories burned for each activity.*/

#include <iostream>
using namespace std;

class Activity 
{
    public:
        virtual double calculateCaloriesBurned() = 0;
        virtual ~Activity() {}
};

class Running : public Activity 
{
    private:
        double distance;
        double time;

    public:
        Running(double d, double t) : distance(d), time(t) {}

        double calculateCaloriesBurned() override 
        {
            return distance * 60;
        }
};

class Cycling : public Activity 
{
    private:
        double speed;
        double time;

    public:
        Cycling(double s, double t) : speed(s), time(t) {}

        double calculateCaloriesBurned() const override 
        {
            double distance = speed * time;
            return distance * 30;
        }
};

int main() 
{
    Running run(5.0, 30.0);
    Cycling cycle(20.0, 1.0);
    cout << "Calories burned running: " << run.calculateCaloriesBurned() << endl;
    cout << "Calories burned cycling: " << cycle.calculateCaloriesBurned() << endl;
}
