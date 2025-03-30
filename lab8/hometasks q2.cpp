/*TASK # 02
An E-commerce website provides multiple ways to calculate the total price of a customer&#39;s
order based on the type of product. There are two main product categories:
1. Electronics: Tax rate 15%
2. Clothing: Tax rate 5%
The website supports different discount methods based on the type of user (Regular or
Premium). Additionally, the website allows combining multiple carts and applying arithmetic
operations to calculate total prices dynamically.

Task Requirements:
1. Create a base class Product with attributes like productID, price, and a virtual function
calculatePrice().
2. Implement two derived classes:
    o Electronics (Applies 15% tax)
    o Clothing (Applies 5% tax)
3. Overload the applyDiscount method to handle different discount types:
    o Percentage discount (e.g., 10% off)
    o Fixed discount (e.g., $20 off)
    o Buy One Get One Free
4. Override the calculatePrice method to apply category-specific tax rates.
5. Implement operator overloading for the ShoppingCart class:
    o + to merge two shopping carts
    o - to remove an item from the cart
    o * to apply bulk discounts
    o / to split cart total among multiple users
6. Create objects for Electronics and Clothing categories, demonstrate method overloading,
overriding, and operator overloading by simulating an online shopping experience.*/

#include <iostream>
using namespace std;

class Product 
{
    protected:
        int productID;
        double price;

    public:
        Product(int id, double p) : productID(id), price(p) {}
        virtual double calculatePrice() = 0;
        
        virtual void applyDiscount(double percentage) 
        {
            price = price - price * (percentage / 100);
            cout << "Discount applied: " << percentage << "% New Price: $" << price << "\n";
        }
        
        virtual void applyDiscount(int fixedAmount) 
        {
            price = price - fixedAmount;
            if (price < 0) price = 0;
            cout << "Fixed Discount applied: $" << fixedAmount << " New Price: $" << price << "\n";
        }
        
        virtual void applyDiscount(string type) 
        {
            if (type == "BOGO") 
            {
                price = price/2;
                cout << "Buy One Get One Free applied. New Price: $" << price << "\n";
            }
        }
        
        double getPrice() const { return price; }
};

class Electronics : public Product 
{
    public:
        Electronics(int id, double p) : Product(id, p) {}
        
        double calculatePrice() override 
        {
            return price * 1.15;
        }
};

class Clothing : public Product 
{
    public:
        Clothing(int id, double p) : Product(id, p) {}
        
        double calculatePrice() override 
        {
            return price * 1.05;
        }
};

class ShoppingCart 
{
    private:
        Product* items[10];
        int itemCount;

    public:
        ShoppingCart() : itemCount(0) {}
        
        void addItem(Product* item) 
        {
            if (itemCount < 10) 
            {
                items[itemCount++] = item;
                cout << "Item added to cart.\n";
            } 
            else
                cout << "Cart is full!\n";
        }
        
        void removeItem() 
        {
            if (itemCount > 0) 
            {
                itemCount--;
                cout << "Last item removed from cart.\n";
            } 
            else
                cout << "Cart is empty!\n";
        }
        
        double calculateTotal() 
        {
            double total=0;
            for (int i=0; i<itemCount; i++) 
            {
                total = total + items[i]->calculatePrice();
            }
            return total;
        }
        
        ShoppingCart operator+(const ShoppingCart& other) 
        {
            ShoppingCart newCart;
            for (int i=0; i<itemCount; i++)
                newCart.addItem(items[i]);

            for (int i=0; i<other.itemCount; i++)
                newCart.addItem(other.items[i]);

            return newCart;
        }
        
        ShoppingCart operator*(double discount) 
        {
            for (int i=0; i<itemCount; i++)
                items[i]->applyDiscount(discount);
            return *this;
        }
        
        ShoppingCart operator/(int users) 
        {
            double share = calculateTotal() / users;
            cout << "Each user pays: $" << share << "\n";
            return *this;
        }
        
        void displayTotal() 
        {
            cout << "Total Cart Price: $" << calculateTotal() << "\n";
        }
};

int main() 
{
    Electronics laptop(1, 1000);
    Clothing shirt(2, 50);
    
    ShoppingCart cart1, cart2;
    cart1.addItem(&laptop);
    cart2.addItem(&shirt);
    
    cart1 = cart1 + cart2;
    cart1.displayTotal();
    
    cart1 * 10;
    cart1.displayTotal();
    
    cart1 / 2;
}
