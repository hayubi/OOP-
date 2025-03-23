/*Visualize a digital multimedia library management system designed to catalog and circulate a diverse range of media items, including books, DVDs, CDs, and magazines. The Media class serves as the base, encapsulating core data members such as title, publicationDate, uniquelD, and publisher. It provides functions like displayInfo() to output media details, checkOut() to process lending, and returnItem() to handle returns. 
Derived classes-Book, DVD, CD, and Magazine-introduce additional attributes: 
• Book includes author, ISBN, and numberOfPages, modifying displayInfo() for books. 
• DVD incorporates director, duration, and rating, updating displayInfo() for movie details. 
• CD includes artist, numberOfTracks, and genre, adapting displayInfo() for music albums. 
The system supports function overloading for searching media by different attributes (e.g., title, author, or publication year). 
*/

#include <iostream>
#include <string>
using namespace std;

class Media
{
    protected:
        string title;
        string publicationDate;
        string uniqueID;
        string publisher;

    public:
        Media(string t, string pubDate, string id, string pub) : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

        virtual void displayInfo() const
        {
            cout << "Title: " << title << "\nPublication Date: " << publicationDate
                << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << endl;
        }

        void checkOut()
        {
            cout << "Item with ID: " << uniqueID << " has been checked out." << endl;
        }

        void returnItem()
        {
            cout << "Item with ID: " << uniqueID << " has been returned." << endl;
        }

        virtual void search(string searchValue) const
        {
            if (title == searchValue)
            {
                displayInfo();
            }
        }

        virtual void search(int year) const
        {
            if (publicationDate.substr(publicationDate.size() - 4) == to_string(year))
            {
                displayInfo();
            }
        }
};

class Book : public Media
{
    private:
        string author;
        string ISBN;
        int numberOfPages;

    public:
        Book(string t, string pubDate, string id, string pub, string auth, string isbn, int numPages) : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(numPages) {}

        void displayInfo() const override
        {
            Media::displayInfo();
            cout << "Author: " << author << "\nISBN: " << ISBN << "\nNumber of Pages: " << numberOfPages << endl;
        }

        void search(string searchValue) const override
        {
            if (title == searchValue || author == searchValue)
            {
                displayInfo();
            }
        }
};

class DVD : public Media
{
    private:
        string director;
        int duration;
        string rating;

    public:
        DVD(string t, string pubDate, string id, string pub, string dir, int dur, string rat) : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rat) {}

        void displayInfo() const override
        {
            Media::displayInfo();
            cout << "Director: " << director << "\nDuration: " << duration << " minutes\nRating: " << rating << endl;
        }

        void search(string searchValue) const override
        {
            if (title == searchValue || director == searchValue)
            {
                displayInfo();
            }
        }
};

class CD : public Media
{
    private:
        string artist;
        int numberOfTracks;
        string genre;

    public:
        CD(string t, string pubDate, string id, string pub, string art, int numTracks, string gen) : Media(t, pubDate, id, pub), artist(art), numberOfTracks(numTracks), genre(gen) {}

        void displayInfo() const override
        {
            Media::displayInfo();
            cout << "Artist: " << artist << "\nNumber of Tracks: " << numberOfTracks << "\nGenre: " << genre << endl;
        }

        void search(string searchValue) const override
        {
            if (title == searchValue || artist == searchValue)
            {
                displayInfo();
            }
        }
};

class Magazine : public Media
{
    private:
        string editor;
        int issueNumber;

    public:
        Magazine(string t, string pubDate, string id, string pub, string ed, int issueNum) : Media(t, pubDate, id, pub), editor(ed), issueNumber(issueNum) {}

        void displayInfo() const override
        {
            Media::displayInfo();
            cout << "Editor: " << editor << "\nIssue Number: " << issueNumber << endl;
        }

        void search(string searchValue) const override
        {
            if (title == searchValue || editor == searchValue)
            {
                displayInfo();
            }
        }

        void search(int year) const override
        {
            if (publicationDate.substr(publicationDate.size() - 4) == to_string(year))
            {
                displayInfo();
            }
        }
};

int main()
{
    Book book1("C++ Programming", "2022-05-15", "B001", "TechPress", "John Doe", "978-3-16-148410-0", 400);
    DVD dvd1("Inception", "2010-07-16", "D001", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD cd1("The Dark Side of the Moon", "1973-03-01", "C001", "EMI", "Pink Floyd", 10, "Rock");
    Magazine mag1("Time", "2023-03-22", "M001", "Time Inc.", "Mark Johnson", 1234);

    cout << "Book Information:\n";
    book1.displayInfo();
    cout << "\nDVD Information:\n";
    dvd1.displayInfo();
    cout << "\nCD Information:\n";
    cd1.displayInfo();
    cout << "\nMagazine Information:\n";
    mag1.displayInfo();

    cout << "\nChecking out items:\n";
    book1.checkOut();
    dvd1.checkOut();

    cout << "\nReturning items:\n";
    book1.returnItem();
    dvd1.returnItem();

    cout << "\nSearching by title (C++ Programming):\n";
    book1.search("C++ Programming");

    cout << "\nSearching by year (2023) in Magazine:\n";
    mag1.search(2023);

    cout << "\nSearching by author (Pink Floyd) in CD:\n";
    cd1.search("Pink Floyd");

    return 0;
}
