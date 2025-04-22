/*Q3. You want to create a combined book by merging the contents of two chapters.
Requirements:
1.⁠ ⁠2. 3. 4. 5. 6. Assume two existing files: chapter1.txt and chapter2.txt. Populate them with some
text before running this.
Open chapter1.txt and chapter2.txt using ifstream in read mode.
Open book.txt using ofstream in ios::app mode.
Read from both files and append the contents sequentially to book.txt.
Ensure a newline is added between chapter contents.
After writing, open and display book.txt contents to verify concatenation*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void mergeChapters() 
{
    ifstream chapter1("chapter1.txt");
    ifstream chapter2("chapter2.txt");
    ofstream book("book.txt", ios::app);

    if (!chapter1 || !chapter2 || !book) 
    {
        cerr << "Error opening one of the files!" << endl;
        return;
    }

    string line;

    book << "--- Chapter 1 ---\n";
    while (getline(chapter1, line)) 
    {
        book << line << endl;
    }
    book << endl;

    book << "--- Chapter 2 ---\n";
    while (getline(chapter2, line)) 
    {
        book << line << endl;
    }
    book << endl;

    chapter1.close();
    chapter2.close();
    book.close();

    cout << "\nChapters merged successfully into book.txt.\n";
}

void displayBook() 
{
    ifstream book("book.txt");
    if (!book) 
    {
        cerr << "Error opening book.txt for reading!" << endl;
        return;
    }

    string line;
    cout << "\n--- Book Contents ---\n";
    while (getline(book, line)) 
    {
        cout << line << endl;
    }
    book.close();
}

int main() 
{
    mergeChapters();
    displayBook();
}
