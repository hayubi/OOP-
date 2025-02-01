/*Task 7) You are tasked with building a simple product management system for an online store.
1. Create a function that allows the addition of a new product to the system. The function should
    take parameters such as product name, price, quantity, and any other relevant details.
2. Implement a function that takes a product ID as input and displays detailed information about the
    product, including its name, price, quantity in stock, and any other relevant details.
3. Design a function that enables the update of product information. It should take a product ID as
    well as the new details (e.g., updated price, quantity, etc.) and modify the existing product’s information accordingly.
4. Create a function that removes a product from the system based on its product ID. Ensure that
    the inventory is updated after the removal.
*/

#include <iostream>
#include <cstring>
using namespace std;

void addProduct(int productID, const char* name, double price, int quantity);
void displayProduct(int productID);
void updateProduct(int productID, const char* name, double price, int quantity);
void removeProduct(int productID);

struct Product 
{
    int productID;
    char name[50];
    double price;
    int quantity;
};

Product inventory[50];
int currentProductCount = 0;

int main() 
{
    int choice;
    int productID;
    int quantity;
    char name[50];
    double price;

    while (true) 
    {
        cout << "Product Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Display Product\n";
        cout << "3. Update Product\n";
        cout << "4. Remove Product\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter product ID: ";
                cin >> productID;
                cin.ignore();
                cout << "Enter product name: ";
                cin.getline(name, 50);
                cout << "Enter product price: ";
                cin >> price;
                cout << "Enter product quantity: ";
                cin >> quantity;
                addProduct(productID, name, price, quantity);
                break;

            case 2:
                cout << "Enter product ID to display: ";
                cin >> productID;
                displayProduct(productID);
                break;

            case 3:
                cout << "Enter product ID to update: ";
                cin >> productID;
                cin.ignore();
                cout << "Enter new product name: ";
                cin.getline(name, 50);
                cout << "Enter new product price: ";
                cin >> price;
                cout << "Enter new product quantity: ";
                cin >> quantity;
                updateProduct(productID, name, price, quantity);
                break;

            case 4:
                cout << "Enter product ID to remove: ";
                cin >> productID;
                removeProduct(productID);
                break;

            case 5:
                cout << "Program Ended" << endl;
                return 0;

            default:
                cout << "Invalid choice. Enter again." << endl;
        }
    }
}

void addProduct(int productID, const char* name, double price, int quantity) 
{
    if (currentProductCount < 50) 
    {
        Product p1;
        p1.productID = productID;
        strncpy(p1.name, name, 49);
        p1.name[49] = '\0';
        p1.price = price;
        p1.quantity = quantity;
        
        inventory[currentProductCount] = p1;
        currentProductCount++;
        cout << "Product added.\n" << endl;
    } 
    else 
    {
        cout << "Inventory is full. Cannot add more products.\n" << endl;
    }
}

void displayProduct(int productID) 
{
    bool found = false;
    for (int i = 0; i < currentProductCount; i++) 
    {
        if (inventory[i].productID == productID) 
        {
            cout << "Product ID: " << inventory[i].productID << endl;
            cout << "Name: " << inventory[i].name << endl;
            cout << "Price: " << inventory[i].price << endl;
            cout << "Quantity in stock: " << inventory[i].quantity << endl;
            found = true;
            break;
        }
    }
    if (!found) 
        {cout << "Product with ID " << productID << " not found.\n" << endl;}
}

void updateProduct(int productID, const char* name, double price, int quantity) 
{
    bool found = false;
    for (int i = 0; i < currentProductCount; i++) 
    {
        if (inventory[i].productID == productID)
        {
            strncpy(inventory[i].name, name, 49);
            inventory[i].name[49] = '\0';
            inventory[i].price = price;
            inventory[i].quantity = quantity;
            cout << "Product updated.\n" << endl;
            found = true;
            break;
        }
    }
    if (!found) 
        {cout << "Product with ID " << productID << " not found.\n" << endl;}
}

void removeProduct(int productID) 
{
    bool found = false;
    for (int i = 0; i < currentProductCount; i++) 
    {
        if (inventory[i].productID == productID) 
        {
            for (int j = i; j < currentProductCount - 1; j++) 
            {
                inventory[j] = inventory[j + 1];
            }
            currentProductCount--;
            cout << "Product removed.\n" << endl;
            found = true;
            break;
        }
    }
    if (!found) 
    {
        cout << "Product with ID " << productID << " not found.\n" << endl;
    }
}