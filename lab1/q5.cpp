/*Q5: Design Event Management System in C++ to facilitate the organization of
events. The program should empower the user to seamlessly manage event
details, including the event name, date, venue, and organizer. Incorporate key
features such as the ability to add events, display comprehensive details of all
events, and perform event searches based on specific dates. To enhance
flexibility and scalability, leverage dynamic memory allocation for storing event
details.
1. Prompt the user to input the total number of events they wish to manage.
2. Dynamically allocate memory to store event details for the specified
number of events.
3. For each event, prompt the user to input:
 Event Name
 Date
 Venue
 Organizer
4. Display all events that match the provided date, including their complete
details.
5. Allow the user to search for events based on a specific date.*/

#include <iostream>
#include <cstring>
using namespace std;

struct Event 
{
    char name[50];
    char date[11];
    char venue[50];
    char organizer[50];
};

int main() 
{
    int numEvents;
    cout << "Enter the total number of events: ";
    cin >> numEvents;

    Event* events = new Event[numEvents];

    cin.ignore();
    for (int i = 0; i < numEvents; i++) 
    {
        cout << "\nEvent " << i + 1 << " details:" << endl;

        cout << "Enter event name: ";
        cin.getline(events[i].name, 50);

        cout << "Enter event date(YYYY-MM-DD): ";
        cin.getline(events[i].date, 11);

        cout << "Enter event venue: ";
        cin.getline(events[i].venue, 50);

        cout << "Enter event organizer: ";
        cin.getline(events[i].organizer, 50);  
    }

    char searchDate[11];
    cout << "\nEnter a date (YYYY-MM-DD) to search for events: ";
    cin >> searchDate;

    cout << "\nEvents on " << searchDate << ":" << endl;
    bool found = false;

    for (int i = 0; i < numEvents; i++) 
    {
        if (strcmp(events[i].date, searchDate) == 0) 
        {
            cout << "\nEvent Name: " << events[i].name << endl;
            cout << "Date: " << events[i].date << endl;
            cout << "Venue: " << events[i].venue << endl;
            cout << "Organizer: " << events[i].organizer << endl;
            found = true;
        }
    }

    if (!found) 
        {cout << "No events found on this date." << endl;}

    delete[] events;
    return 0;
}
