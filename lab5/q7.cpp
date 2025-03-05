/*Task-07:
Implement a restaurant ordering system that holds information about the restaurant’s menus, menu
items, orders, and payments. Identify the relationship between the five entities mentioned. Keep in
mind the following information as well:
a) Menu Items hold two things: food name and food price.
b) Menu is a class that holds an array of menu items. You can have different functions to add and
remove items, or display the entire menu.
c) Restaurant ordering system has one menu.
d) Any staff member can place an order to the system on behalf of a customer. Theorder class
consists of one or more menu items and a payment.
e) Payment is a class that holds the amount of money that a customer needs to pay.This is
generated when the order is placed.*/

#include <iostream>
#include <string>
using namespace std;

class MenuItem 
{
    private:
        string name;
        double price;

    public:
        MenuItem(string n="", double p=0.0) : name(n), price(p) {}
        
        string getname() { return name; }
        double getprice() { return price; }
};

class Menu 
{
    private:
        MenuItem items[10];
        int itemcount;

    public:
        Menu() : itemcount(0) {}

        void addItem(string fname, double fprice) 
        {
            if (itemcount < 10) 
                items[itemcount++] = MenuItem(fname, fprice);
            else 
                cout << "Menu is full" << endl;
        }

        void removeItem(string fname) 
        {
            bool found = false;
            for (int i=0; i<itemcount; i++) 
            {
                if (items[i].getname() == fname) 
                {
                    for (int j=i; j < itemcount-1; j++) 
                    {
                        items[j] = items[j+1];
                    }
                    itemcount--;
                    cout << fname << " removed from  menu" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) 
                cout << "Item not found" << endl;
        }

        void displayMenu() 
        {
            cout << "\n--Restaurant Menu--" << endl;
            for (int i=0; i<itemcount; i++) 
            {
                cout << "Food: " << items[i].getname() << " Price: " << items[i].getprice() << " rupees" << endl;
            }
        }

        MenuItem* getItems() { return items; }
        int getItemCount() { return itemcount; }
};

class Payment 
{
    private:
        double amount;

    public:
        Payment(double a=0.0) : amount(a) {}

        void displayPayment() 
        {
            cout << "Total amount to pay: Rs." << amount << endl;
        }

        double getamount() { return amount; }
};

class Order 
{
    private:
        MenuItem orderItems[10];
        int itemCount=0;
        Payment* payment;

    public:
        Order() : payment(nullptr) {}

        void addItemToOrder(MenuItem item) 
        {
            if (itemCount < 10) 
                orderItems[itemCount++] = item;
            else 
                cout << "Order is full" << endl;
        }

        double calculateTotal() 
        {
            double total=0.0;
            for (int i=0; i<itemCount; i++) 
            {
                total = total + orderItems[i].getprice();
            }
            return total;
        }

        void generatePayment() 
        {
            double totalAmount = calculateTotal();
            payment = new Payment(totalAmount);
        }

        void displayOrder() 
        {
            cout << "\n--Order details--" << endl;
            for (int i=0; i<itemCount; i++) 
            {
                cout << "Food: " << orderItems[i].getname() << " Price: Rs." << orderItems[i].getprice() << endl;
            }
            if (payment) 
                payment->displayPayment();
            else 
                cout << "No payment generated" << endl;
        }
};

int main() 
{
    Menu menu;
    menu.addItem("Biryani", 150.0);
    menu.addItem("Korma", 200.0);
    menu.addItem("Karahi", 250.0);
    menu.displayMenu();

    Order order;
    order.addItemToOrder(MenuItem("Biryani", 150.0));
    order.addItemToOrder(MenuItem("Korma", 200.0));
    order.generatePayment();
    order.displayOrder();

    cout << endl;
    menu.removeItem("Karahi");
    menu.displayMenu();
}