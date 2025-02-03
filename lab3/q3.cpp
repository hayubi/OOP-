/*Task 3) Create a class that includes a data member that holds a “serial number” for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on. To do this, you’ll need another data member that records a count of how many objects have been created so far. (This member should apply to the class as a whole; not to individual objects. What keyword specifies this?) Then, as each object is created, its constructor can examine this count member variable to determine the appropriate serial number for the new object.
Add a member function that permits an object to report its own serial number. Then write a main() program that creates three objects and queries each one about its serial number. They should respond I am object number 2, and so on.
 */

#include <iostream>
using namespace std;

class Serial
{
    private:
        static int count; // to ensure that it is shared among all instances of the class rather than being tied to a specific object
        int serialnumber;
    public:
        Serial()
            {serialnumber = ++count;}

        void reportOwnSerial() const
        {
            cout << "I am object number " << serialnumber << endl;
        }
};

int Serial::count = 0;

int main()
{
    Serial s1, s2, s3;
    s1.reportOwnSerial();
    s2.reportOwnSerial();
    s3.reportOwnSerial();
}