/*Task 1) Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor should initialize this data to 0, and another should initialize it to fixed values. Another member function should display it in 11:59:59 format. The final member function should add two objects of type time passed as arguments.
A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized. Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should display the value of this third variable. Make appropriate member functions const.
*/

#include <iostream>
using namespace std;
class Time
{
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        Time() : hours(0), minutes(0), seconds(0) {}
        Time(int phours, int pminutes, int pseconds) : hours(phours), minutes(pminutes), seconds(pseconds) {}

        void display() const // const so that the display function does not modify any member variables of the class
        {
            if (hours < 10)
                cout << "0:";
            else
                cout << hours << ":";

            if (minutes < 10)
                cout << "0:";
            else
                cout << minutes << ":";

            if (seconds < 10)
                cout << "0:";
            else
                cout << seconds << endl;
        }

        void addTwoObjects(const Time& t1, const Time& t2) // passed by reference so that values are not changed--const,&
        {
            seconds = t1.seconds + t2.seconds;
            minutes = t1.minutes + t2.minutes + (seconds/60);
            hours = t1.hours + t2.hours + (minutes/60);
            seconds = seconds % 60;
            minutes = minutes % 60;
        } 
};

int main()
{
    const Time t1(11, 59, 59);
    const Time t2(2, 20, 30);
    Time t3;
    t3.addTwoObjects(t1, t2);
    t3.display();
}