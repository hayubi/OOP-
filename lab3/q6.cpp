/*Task 6) Create a class called Smartphone with the following attributes:
•	Company
•	Model
•	Display Resolution
•	RAM
•	ROM
•	Storage
Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.
For example:
•	Make a phone call
•	Send a message
•	Connect to the wifi
•	Browse the internet
Create different smartphone objects. Set their attributes using the setter functions and display their attributes after using the getter functions to fetch the attributes.
*/

#include <iostream>
using namespace std;

class Smartphone
{
    private:
        string company;
        string model;
        string displayResolution;
        int ram;
        int rom;
        int storage;
    public:
        void setCompany(const string& pcompany)
            {company = pcompany;}
        void setModel(const string& pmodel)
            {model = pmodel;}
        void setDisplayRes(const string& pdisplayres)
            {displayResolution = pdisplayres;}
        void setRam(int pram)
            {ram = pram;}
        void setRom(int prom)
            {rom = prom;}
        void setStorage(int pstorage)
            {storage = pstorage;}

        string getCompany() const
            {return company;}
        string getModel() const
            {return model;}
        string getDisplayRes() const
            {return displayResolution;}
        int getRam() const
            {return ram;}
        int getRom() const
            {return rom;}
        int getStorage() const
            {return storage;}
        
        void makeCall()
            {cout << "Making a phone call." << endl;}
        void sendMessage()
            {cout << "Sending a message." << endl;}
        void connectWifi()
            {cout << "Connecting to Wifi." << endl;}
        void browseInternet()
            {cout << "Browsing Internet." << endl;}
};

int main()
{
    Smartphone sp1, sp2;

    sp1.setCompany("Apple");
    sp1.setModel("iPhone 16 pro max");
    sp1.setDisplayRes("2532 x 1170");
    sp1.setRam(4);
    sp1.setRom(128);
    sp1.setStorage(256);

    sp2.setCompany("Samsung");
    sp2.setModel("Galaxy S23 ultra");
    sp2.setDisplayRes("2400 x 1080");
    sp2.setRam(8);
    sp2.setRom(128);
    sp2.setStorage(128);

    cout << "Phone 1 Details: " << endl;
    cout << "Company: " << sp1.getCompany() << endl;
    cout << "Model: " << sp1.getModel() << endl;
    cout << "Display Resolution: " << sp1.getDisplayRes() << endl;
    cout << "RAM: " << sp1.getRam() << " GB" << endl;
    cout << "ROM: " << sp1.getRom() << " GB" << endl;
    cout << "Storage: " << sp1.getStorage() << " GB" << endl;

    sp1.makeCall();
    sp1.sendMessage();
    sp1.connectWifi();
    sp1.browseInternet();
    cout << endl;

    cout << "Phone 2 Details: " << endl;
    cout << "Company: " << sp2.getCompany() << endl;
    cout << "Model: " << sp2.getModel() << endl;
    cout << "Display Resolution: " << sp2.getDisplayRes() << endl;
    cout << "RAM: " << sp2.getRam() << " GB" << endl;
    cout << "ROM: " << sp2.getRom() << " GB" << endl;
    cout << "Storage: " << sp2.getStorage() << " GB" << endl;

    sp2.makeCall();
    sp2.sendMessage();
    sp2.connectWifi();
    sp2.browseInternet();
    cout << endl;

}