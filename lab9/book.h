#ifndef BOOK
#define BOOK
class book
{
    protected:
        string title;
        string author;
        string ISBN;

    public:
        string getTitle();
        string getAuthor();
        string getISBN();
}
#endif