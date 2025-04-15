#include "book.h"

Book::Book(string t, string a, string isbn) 
{
    title = t;
    author = a;
    ISBN = isbn;

    string getTitle();
    string getAuthor();
    string getISBN();
}

string Book::getTitle() 
{
    return title;
}

string Book::getAuthor() 
{
    return author;
}

string Book::getISBN() 
{
    return ISBN;
}