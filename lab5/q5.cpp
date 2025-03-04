/*Task-05:
Keeping in mind our previous car example, write a class that represents a car, and use aggregation and
composition to combine different components like engine, wheels, headlights and steering to create the
car object.
Hint: create the individual classes first before performing the composition. Remember
that for aggregation, you will need pointers! You’ll be needing constructors and setters to
set these values in case of aggregation. Same hint applies to other questions.*/

#include <iostream>
using namespace std;

class Engine
{
    public:
        Engine() {}

        void start()
        {
            cout << "Engine has started" << endl;
        }

        void stop()
        {
            cout << "Engine has stopped" << endl;
        }
};

class Wheels 
{
    public:
        Wheels() {}
    
        void rotate() 
        {
            cout << "Wheels are rotating" << endl;
        }
};

class Headlights 
{
    public:
        Headlights() {}
    
        void turnOn() 
        {
            cout << "Headlights are on" << endl;
        }
    
        void turnOff() 
        {
            cout << "Headlights are off" << endl;
        }
};

class Steering 
{
    public:
        Steering() {}
    
        void turnLeft() 
        {
            cout << "Steering turned left" << endl;
        }
    
        void turnRight() 
        {
            cout << "Steering turned right" << endl;
        }
};

class Car
{
    private:
        Engine engine;
        Wheels wheels;
        Headlights* headlights = nullptr;
        Steering* steering = nullptr;

    public:
        Car(Headlights* h, Steering* s) 
        {
            headlights = h;
            steering = s;
        }

        void startCar() 
        {
            engine.start();
            wheels.rotate();
            if (headlights) 
            {
                headlights->turnOn();
            }
        }

        void stopCar() 
        {
            engine.stop();
            if (headlights) 
            {
                headlights->turnOff();
            }
        }

        void turnCarLeft() 
        {
            if (steering) 
            {
                steering->turnLeft();
            }
        }

        void turnCarRight() 
        {
            if (steering) 
            {
                steering->turnRight();
            }
        }
};

int main()
{
    Headlights h;
    Steering s;

    Car car(&h, &s);
    car.startCar();
    car.turnCarLeft();
    car.turnCarRight();
    car.stopCar();
}