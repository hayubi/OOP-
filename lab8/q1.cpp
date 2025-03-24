#include <iostream>
#include <string>
using namespace std;

class Device 
{
    protected:
        string deviceID, deviceType;
        double powerRating;
        bool status;

    public:
        Device(string id, string type, double rating) : deviceID(id), deviceType(type), powerRating(rating), status(false) {}
        
        virtual void turnOn() { status = true; cout << deviceType << " [ID: " << deviceID << "] turned ON.\n"; }
        void turnOff() { status = false; }
        
        virtual double calculatePowerUsage(int hours) = 0;
        string getDeviceType() { return deviceType; }
        string getDeviceID() { return deviceID; }
};

class Light : public Device 
{
    public:
        Light(string id, string type, double rating) : Device(id, type, rating) {}

        double calculatePowerUsage(int hours) override 
        { 
            return powerRating * hours; 
        }
};

class Fan : public Device 
{
    private:
        int speedFactor;

    public:
        Fan(string id, string type, double rating, int speed) : Device(id, type, rating), speedFactor(speed) {}

        void turnOn() override 
        {
            status = true;
            cout << deviceType << " [ID: " << deviceID << "] turned ON at Speed " << speedFactor << ".\n";
        }

        double calculatePowerUsage(int hours) override 
        { 
            return powerRating * hours * speedFactor; 
        }
};

class AirConditioner : public Device 
{
    private:
        double desiredTemp;

    public:
        AirConditioner(string id, string type, double rating, double temp) : Device(id, type, rating), desiredTemp(temp) {}

        void turnOn() override 
        {
            status = true;
            cout << deviceType << " [ID: " << deviceID << "] turned ON. Cooling to " << desiredTemp << "°C.\n";
        }

        double calculatePowerUsage(int hours) override 
        { 
            return powerRating * hours * 0.8;  // Assuming cooling efficiency
        }
};

class SecuritySystem : public Device 
{
    public:
        SecuritySystem(string id, string type, double rating) : Device(id, type, rating) {}

        void turnOn() override 
        {
            status = true;
            cout << deviceType << " [ID: " << deviceID << "] activated.\n";
        }

        double calculatePowerUsage(int hours) override 
        { 
            return powerRating * hours + 100; // Security checks add constant power usage
        }

        friend class MaintenanceTool;
        friend void accessSecurityLogs(SecuritySystem &secSys);
};

void accessSecurityLogs(SecuritySystem &secSys) 
{
    cout << "User: U002 - Security Logs Accessed:\n";
    cout << "- Intrusion Detected at 3:00 AM\n";
    cout << "- System Reset Required\n";
}

class MaintenanceTool 
{
    public:
        static void resetSecurityAlert(SecuritySystem &secSys) 
        {
            cout << "Security Alert Reset\n";
        }
};

class User 
{
    private: 
        string userID;
        string userRole;
        int accessLevel;

    public:
        User(string id, string role, int level) : userID(id), userRole(role), accessLevel(level) {}
        
        void viewAccessibleDevices(Device *devices[], int size) 
        {
            cout << "User: " << userID << " - Accessible Devices:\n";
            for (int i = 0; i < size; i++) 
            {
                if (devices[i]->getDeviceType() != "Home Alarm") 
                    cout << "- " << devices[i]->getDeviceType() << "\n";
            }
        }

        void accessSecurityLogs(SecuritySystem &secSys) 
        {
            if (userRole == "Maintenance Staff") 
                ::accessSecurityLogs(secSys); 
            else 
                cout << "Access Denied: Security logs are restricted.\n";
        }
};

int main() 
{
    User user1("U001", "Regular User", 1);
    User user2("U002", "Maintenance Staff", 2);
    
    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 75, 3);
    AirConditioner ac1("AC001", "Split AC", 1500, 25);
    SecuritySystem secSys1("S001", "Home Alarm", 100);
    
    Device* devices[] = { &light1, &fan1, &ac1, &secSys1 };
    
    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    secSys1.turnOn();
    
    cout << "\nPower Consumption:\n";
    cout << "LED Light: " << light1.calculatePowerUsage(5) << " Watts\n";
    cout << "Ceiling Fan: " << fan1.calculatePowerUsage(3) << " Watts\n";
    cout << "Split AC: " << ac1.calculatePowerUsage(6) << " Watts\n";
    cout << "Security System: " << secSys1.calculatePowerUsage(24) << " Watts\n";
    
    cout << endl;
    user1.viewAccessibleDevices(devices, 4);
    cout << endl;
    user2.accessSecurityLogs(secSys1);
}