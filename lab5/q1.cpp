/*Task-01:
Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas
variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main functions create 3 Squares with different sideLength. Call the area method for each of
those Square objects. After each time the area method is called, call that square’s getters for area and allareas to display the updated values.*/

#include <iostream>
using namespace std;

class Square
{
    private:
        float sideLength;
        float area;
        static float allareas;
    
    public:
        Square() : sideLength(0.0), area(0.0) {}
        Square(float l) : sideLength(l) {}

        void calculateArea()
        {
            area = sideLength*sideLength;
            allareas = allareas + area;
        }

        float getsideLength() { return sideLength; }
        float getArea() { return area; }
        static float getallAreas() { return allareas; }

        void setsideLength(float l) { sideLength = l; }
        void setarea(float a) { area = a; }
};

float Square::allareas=0.0;

int main()
{
    Square s1(5.0);
    Square s2(2.2);
    Square s3(3.3);
    
    s1.calculateArea();
    cout << endl;
    cout << "Square 1: " << endl;
    cout << "Length: " << s1.getsideLength() << endl;
    cout << "Area: " << s1.getArea() << endl;
    cout << "All Areas: " << Square::getallAreas() << endl;
    cout << endl;

    s2.calculateArea();
    cout << "Square 2: " << endl;
    cout << "Length: " << s2.getsideLength() << endl;
    cout << "Area: " << s2.getArea() << endl;
    cout << "All Areas: " << Square::getallAreas() << endl;
    cout << endl;

    s3.calculateArea();
    cout << "Square 3: " << endl;
    cout << "Length: " << s3.getsideLength() << endl;
    cout << "Area: " << s3.getArea() << endl;
    cout << "All Areas: " << Square::getallAreas() << endl;
}