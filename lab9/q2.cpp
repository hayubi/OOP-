/*Task 02
Problem: A homeowner wants to integrate smart lights and thermostats from different
brands into a single app. The system must provide a unified way to turn devices on/off,
adjust settings, and check statuses without requiring users to interact with brand-specific
interfaces. Future devices (e.g., smart locks) should integrate without altering the core
system.
Classes and Structure:
• Abstract Class SmartDevice:
o Member Functions:

▪ turnOn(): Pure virtual function to activate the device.
▪ turnOff(): Pure virtual function to deactivate the device.
▪ getStatus(): Pure virtual function to return the device’s current state.

• Derived Class LightBulb:
o Data Members:
▪ isOn (bool): Tracks if the light is on/off.
▪ brightness (int): Stores brightness level (0-100%).
o Implements turnOn(), turnOff(), and getStatus() for light control.
• Derived Class Thermostat:
o Data Members:
▪ isOn (bool): Tracks if the thermostat is active.
▪ temperature (double): Stores the current temperature setting.
o Implements turnOn(), turnOff(), and getStatus() for temperature control.

Flow:
• Create LightBulb and Thermostat objects.
• Turn devices on/off and display their statuses.*/

#include <iostream>
#include <string>
using namespace std;

class SmartDevice 
{
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual string getStatus() const = 0;
        virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice 
{
    private:
        bool isOn;
        int brightness;

    public:
        LightBulb() : isOn(false), brightness(100) {}

        void turnOn() override 
        {
            isOn = true;
            brightness = 100;
            cout << "LightBulb turned ON with brightness " << brightness << "%" << endl;
        }

        void turnOff() override 
        {
            isOn = false;
            cout << "LightBulb turned OFF" << endl;
        }

        string getStatus() const override 
        {
            if (isOn)
                return "LightBulb is ON at " + to_string(brightness) + "%";
            else
                return "LightBulb is OFF";
        }
};

class Thermostat : public SmartDevice 
{
    private:
        bool isOn;
        double temperature;

    public:
        Thermostat() : isOn(false), temperature(22.0) {}

        void turnOn() override 
        {
            isOn = true;
            temperature = 22.0;
            cout << "Thermostat turned ON at " << temperature << "°C" << endl;
        }

        void turnOff() override 
        {
            isOn = false;
            cout << "Thermostat turned OFF" << endl;
        }

        string getStatus() const override 
        {
            if (isOn)
                return "Thermostat is ON at " + to_string(temperature) + "°C";
            else
                return "Thermostat is OFF";
        }
};

int main() 
{
    const int deviceCount = 2;
    SmartDevice* devices[deviceCount];

    devices[0] = new LightBulb();
    devices[1] = new Thermostat();

    cout << "\nTurning all devices ON...\n";
    for (int i=0; i < deviceCount; i++) 
    {
        devices[i]->turnOn();
        cout << devices[i]->getStatus() << endl;
    }

    cout << "\nTurning all devices OFF...\n";
    for (int i=0; i < deviceCount; i++) 
    {
        devices[i]->turnOff();
        cout << devices[i]->getStatus() << endl;
    }

    for (int i=0; i < deviceCount; i++) 
    {
        delete devices[i];
    }
}
