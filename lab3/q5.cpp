/*Task 5) Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that stores information about the current year. The user is allowed to store their tasks to do against each day. Assume only one entry is needed per day.
Create the following methods for your class:
•	Add a task. This function accepts three parameters: task details, date and month. It should add a task on the day specified.
•	Remove a task. Accepts the date and month as a parameter to remove the task from.
•	Show tasks. This method should go through all of your months and print all the tasks allocated.
Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how you’ll remove a task, and display the updated task list.
*/

#include <iostream>
#include <string>

using namespace std;

class Calendar 
{
    private:
        int year;
        string months[12][31];
        
    public:
        Calendar(int y) : year(y) 
        {
            for (int month=0; month<12; ++month) 
            {
                for (int day=0; day<31; ++day) 
                {
                    months[month][day] = "";
                }
            }
        }

        void add_task(const string &task, int day, int month) 
        {
            if (day>0 && day<=31) 
            {
                if ((month == 2 && day > 28) || (month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
                    {cout << "Invalid day for month " << month << endl;}
                else 
                    {months[month - 1][day - 1] = task;}
            } 
            else 
                {cout << "Invalid date: " << day << endl;}
        }

        void remove_task(int day, int month) 
        {
            if (day>0 && day<=31) 
            {
                if ((month == 2 && day > 28) || (month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
                    {cout << "Invalid day for month " << month << endl;}
                else 
                    {months[month - 1][day - 1] = "";}
            } 
            else 
                {cout << "Invalid date: " << day << endl;}
        }

        void show_tasks() 
        {
            for (int month=0; month<12; ++month) 
            {
                cout << "Month " << (month + 1) << ":" << endl;
                for (int day = 0; day < 31; ++day) 
                {
                    if (months[month][day] != "") 
                    {
                        cout << "  Day " << (day+1) << ": " << months[month][day] << endl;
                    }
                }
                cout << endl;
            }
        }
};

int main() 
{
    Calendar calendar(2025);

    calendar.add_task("Meeting", 7, 8);
    calendar.add_task("Flight to Dubai", 11, 3);
    calendar.add_task("Cricket Match", 25, 5);
    calendar.add_task("Project Deadline", 30, 4);
    calendar.add_task("Appointment", 9, 5);
    calendar.add_task("Birthday", 31, 2);

    cout << "Tasks:" << endl;
    calendar.show_tasks();
    calendar.remove_task(25, 5);
    cout << "Updated Tasks:" << endl;
    calendar.show_tasks();
}