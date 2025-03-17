/*Task 02 
Picture an innovative design tool aimed at architects and graphic designers that allows for creating, manipulating, and analyzing various geometric shapes. The system is structured around a Shape class, which includes data members such as position, color, and an optional borderThickness. It provides functions like draw() for rendering, calculateArea() for area measurement, and calculatePerimeter() for perimeter computation. 
Derived classes such as Circle, Rectangle, Triangle, and Polygon introduce their own properties-for example, a Circle includes radius and center position, while a Rectangle includes width, height, and top-left corner position. Each derived class overrides draw(), calculateArea(), and calculate Perimeter() to handle their respective geometries. 
*/

#include <iostream>
#include <cmath>
#define M_PI 3.1415
using namespace std;

class Shape 
{
    protected:
        int x;
        int y;
        string color;
        double borderThickness;

    public:
        Shape(int px, int py, string pcolor, double pbt = 0.0) : x(px), y(py), color(pcolor), borderThickness(pbt) {}
        
        virtual void draw() const = 0;
        virtual double calculateArea() const = 0;
        virtual double calculatePerimeter() const = 0;

        virtual ~Shape() {}
};

class Circle : public Shape 
{
    private:
        double radius;

    public:
        Circle(int px, int py, string pcolor, double pbt = 0.0, double r) : Shape(px, py, pcolor, pbt), radius(r) {}
        
        void draw() const override 
        {
            cout << "Drawing Circle at (" << x << ", " << y << ") with radius " << radius << "\n";
        }
        
        double calculateArea() const override 
        {
            return M_PI * radius * radius;
        }
        
        double calculatePerimeter() const override 
        {
            return 2 * M_PI * radius;
        }
};

class Rectangle : public Shape 
{
    private:
        double width, height;

    public:
        Rectangle(int px, int py, string pcolor, double pbt = 0.0, double w, double h) : Shape(px, py, pcolor, pbt), width(w), height(h) {}
        
        void draw() const override 
        {
            cout << "Drawing Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
        }
        
        double calculateArea() const override 
        {
            return width * height;
        }
        
        double calculatePerimeter() const override 
        {
            return 2 * (width + height);
        }
};

class Triangle : public Shape 
{
    private:
        double a, b, c;

    public:
        Triangle(int x, int y, string color, double a, double b, double c, double borderThickness = 0.0) : Shape(x, y, color, borderThickness), a(a), b(b), c(c) {}
        
        void draw() const override 
        {
            cout << "Drawing Triangle at (" << x << ", " << y << ") with sides " << a << ", " << b << ", " << c << "\n";
        }
        
        double calculateArea() const override 
        {
            double s = (a + b + c) / 2;
            return sqrt(s * (s - a) * (s - b) * (s - c));
        }
        
        double calculatePerimeter() const override 
        {
            return a + b + c;
        }
};

int main() 
{
    Circle c(10, 15, "Red", 5.0);
    Rectangle r(5, 10, "Blue", 8.0, 6.0);
    Triangle t(2, 3, "Green", 3.0, 4.0, 5.0);
    
    c.draw();
    cout << "Area: " << c.calculateArea() << ", Perimeter: " << c.calculatePerimeter() << "\n\n";
    
    r.draw();
    cout << "Area: " << r.calculateArea() << ", Perimeter: " << r.calculatePerimeter() << "\n\n";
    
    t.draw();
    cout << "Area: " << t.calculateArea() << ", Perimeter: " << t.calculatePerimeter() << "\n";
}