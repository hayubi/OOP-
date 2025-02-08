/*Task 7) Create a class for a stationary shop. The stationary shop maintains a list for all the items that it sells (hint: array of strings), and another list with the prices of the items (hint: array of prices).
Create a menu-driven program to:
•	Allow the shop owner to add the items and their prices.
•	Fetch the list of items
•	Edit the prices of the items
•	View all the items and their prices
Create a receipt that the shopkeeper can share with their customers. The receipt can only be created after the shopkeeper inputs the items and their amounts bought by the customer.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class StationaryShop 
{
    private:
        string items[100];
        double prices[100];
        int itemcount;
    public:
        StationaryShop() : itemcount(0) {}

        void addItem(string item, double price) 
        {
            if (itemcount < 100) 
            {
                items[itemcount] = item;
                prices[itemcount] = price;
                itemcount++;
                cout << "Item added." << endl;
            } 
            else 
                {cout << "Cannot add more items." << endl;}
        }

        void showItems() const 
        {
            if (itemcount == 0) 
            {
                cout << "No items available." << endl;
                return;
            }

            cout << "Items Available:" << endl;
            for (int i=0; i<itemcount; i++) 
            {
                cout << i+1 << ". " << items[i] << " Rs. " << fixed << setprecision(2) << prices[i] << endl;
            }
        }

        void editPrice(int index, double newPrice) 
        {
            if (index >= 1 && index <= itemcount)
            {
                prices[index-1] = newPrice;
                cout << "Price updated." << endl;
            } 
            else 
                {cout << "Invalid item number." << endl;}
        }

        void displayAllItems() const 
        {
            if (itemcount == 0) 
            {
                cout << "No items available." << endl;
                return;
            }

            cout << "\nItems Available:" << endl;
            for (int i=0; i<itemcount; i++) 
            {
                cout << i+1 << ". " << items[i] << " Rs. " << fixed << setprecision(2) << prices[i] << endl;
            }
        }

        void createReceipt() 
        {
            if (itemcount == 0) 
            {
                cout << "No items available." << endl;
                return;
            }
            
            double total=0;
            int itemNumber, quantity;
            cout << "\nReceipt:" << endl;
            while (true) 
            {
                cout << "Enter item number to buy (0 to finish): ";
                cin >> itemNumber;
                if (itemNumber == 0) 
                    {break;}

                if (itemNumber < 1 || itemNumber > itemcount) 
                {
                    cout << "Invalid item number. Please try again." << endl;
                    continue;
                }

                cout << "Enter quantity for " << items[itemNumber-1] << ": ";
                cin >> quantity;

                double itemTotal = prices[itemNumber - 1] * quantity;
                total = total + itemTotal;

                cout << "Added: " << items[itemNumber - 1] << " x " << quantity << " = Rs. " << fixed << setprecision(2) << itemTotal << endl;

                string proceed;
                cout << "Do you want to add more items? (yes/no): ";
                cin >> proceed;

                if (proceed == "no") 
                    {break;}
            }

            cout << "\nFinal Receipt:" << endl;
            cout << "Total: Rs. " << fixed << setprecision(2) << total << endl;
        }
};

int main() 
{
    StationaryShop shop;
    int choice;
    string item;
    double price;
    int itemNumber;
    double newPrice;
    
    do 
    {
        cout << "\nStationary Shop Menu" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Show Items" << endl;
        cout << "3. Edit Item Price" << endl;
        cout << "4. Create Receipt" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, item);
                cout << "Enter price: ";
                cin >> price;
                shop.addItem(item, price);
                break;

            case 2:
                shop.showItems();
                break;

            case 3:
                cout << "Enter item number to edit: ";
                cin >> itemNumber;
                cout << "Enter new price: ";
                cin >> newPrice;
                shop.editPrice(itemNumber, newPrice);
                break;

            case 4:
                shop.createReceipt();
                break;

            case 5:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 5);
}
