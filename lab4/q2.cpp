/*TASK # 02
Scenario:
A library system allows users to borrow and return books. The system should:
1. Add new books to the collection.
2. Borrow books (check availability).
3. Return books.
4. Display all available books.

Requirements:
     Implement a Book class with attributes: ID, title, author, availability.
     Implement a Library class with:
1. Method to add a book (with unique ID).
2. Method to borrow a book (updates availability).
3. Method to return a book (marks it available).
4. Method to display all available books.
     Store book records dynamically using pointers and DMA.
     Use constructor overloading to initialize books with or without availability status.*/

#include <iostream>
#include <string>
using namespace std;

class Book
{
    private:
        int ID;
        string title;
        string author;
        char availability;
    
    public:
        Book(int pID, string pTitle, string pAuthor, char pAvailability = 'A') : ID(pID), title(pTitle), author(pAuthor), availability(pAvailability) {}

        void setID(char newID)
            {ID = newID;}

        void setTitle(char newTitle)
            {title = newTitle;}

        void setAuthor(char newAuthor)
            {author = newAuthor;}

        void setAvailability(char newAvailability)
            {availability = newAvailability;}

        int getID() const
            {return ID;}
        string getTitle() const
            {return title;}
        string getAuthor() const
            {return author;}
        char getAvailability() const
            {return availability;}


};

class Library
{
    private:
        Book** books;
        int count;
        int maxbooks;

    public:
        Library(int max)
        {
            maxbooks = max;
            count = 0;
            books = new Book*[maxbooks];
        }

        void addBook(int uniqueID, string pTitle, string pAuthor, char pAvailability = 'A')
        {
            if (count < maxbooks)
            {
                books[count] = new Book(uniqueID, pTitle, pAuthor, pAvailability);
                count++;
            }
            else
                {cout << "Library is full, cannot add more books." << endl;}
        }

        void borrowBook(int idToBorrow)
        {
            bool found = false;
            for (int i=0; i<count; i++)
            {   
                if (books[i]->getID() == idToBorrow && books[i]->getAvailability() == 'A')
                {
                    books[i]->setAvailability('B'); //SYNTAX -- ('B')
                    found = true;
                    cout << books[i]->getTitle() << " has been successfully borrowed." << endl;
                    break;
                }
            }
            if (found != true)
                cout << "Book not found.";
        }

        void returnBook(int bookID)
        {
            bool found = true;
            for (int i=0; i<count; i++)
            {
                if (books[i]->getID() == bookID && books[i]->getAvailability() == 'B')
                {
                    books[i]->setAvailability('A');
                    found = false;
                    cout << books[i]->getTitle() << " is successfully returned." << endl;
                    break;
                }
            }
            if (found != false)
                cout << "Book not found.";
        }

        void displayBooks() const
        {
            cout << "Books Available:" << endl;
            for (int i=0; i<count; i++)
            {
                if (books[i]->getAvailability() == 'A')
                {
                    cout << "ID: " << books[i]->getID() << endl;
                    cout << "Title: " << books[i]->getTitle() << endl;
                    cout << "Author: " << books[i]->getAuthor() << endl;
                    cout << "Availability: yes" << endl;
                }
                else
                {
                    cout << "ID: " << books[i]->getID() << endl;
                    cout << "Title: " << books[i]->getTitle() << endl;
                    cout << "Author: " << books[i]->getAuthor() << endl;
                    cout << "Availability: no, borrowed" << endl;
                }
            }
        }

        ~Library()
        {
            for (int i=0; i< count; i++)
            {
                delete books[i];
            }
            delete[] books;
        }
};

int main()
{
    int maxBooks;
    cout << "Enter the maximum number of books the library can hold: ";
    cin >> maxBooks;

    Library lib(maxBooks);

    int choice;
    do 
    {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add a Book\n";
        cout << "2. Borrow a Book\n";
        cout << "3. Return a Book\n";
        cout << "4. Display Available Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                int newID;
                string title, author;
                char availability;
                cout << "Enter book ID: ";
                cin >> newID;
                cin.ignore();
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter availability ('A' for available, 'B' for borrowed): ";
                cin >> availability;

                lib.addBook(newID, title, author, availability);
                break;
            }

            case 2: 
            {
                int bookID;
                cout << "Enter the book ID to borrow: ";
                cin >> bookID;
                lib.borrowBook(bookID);
                break;
            }

            case 3: 
            {
                int bookID;
                cout << "Enter the book ID to return: ";
                cin >> bookID;
                lib.returnBook(bookID);
                break;
            }

            case 4:
                lib.displayBooks();
                break;

            case 5:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
}