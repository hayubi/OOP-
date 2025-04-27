/*Q5. You're building a tool to search and replace a specific word in a text file without
rewriting the entire file.
Requirements:
1. Create and populate a file named data.txt with a few sentences. (e.g., AI is the
future. AI will transform the world. Embrace AI now.)
2. Prompt the user to enter:
    ○ A searchWord (e.g., "AI")
    ○ A replacementWord (e.g., "ML")
3. Open the file using fstream in ios::in | ios::out mode.
4. Search for the searchWord using seekg() and read sequentially.
5. When found:
    ○ Use tellg() to get the current read pointer location.
    ○ Use seekp() to position the write pointer.
    ○ Replace the word only if the replacement is of equal or smaller length to
avoid shifting content.
6. If the word is replaced, pad with spaces if needed (e.g., replacing "AI" with "ML" or
"XX").
7. After all replacements, display the updated file.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    fstream file;
    file.open("data.txt", ios::out);
    if (!file) 
    {
        cout << "Error in creating file" << endl;
    }
    file << "AI is the future.\n";
    file << "AI will transform the world.\n";
    file << "Embrace AI now.\n";
    file.close();

    string searchWord, replacementWord;
    cout << "Enter the search word: ";
    cin >> searchWord;
    cout << "Enter the replacement word: ";
    cin >> replacementWord;

    file.open("data.txt", ios::in | ios::out);
    if (!file) 
    {
        cout << "Error opening file" << endl;
    }

    char ch;
    int i=0;

    while (file.get(ch)) 
    {
        if (ch == searchWord[0]) 
        {
            int currentPos = file.tellg();
            i=1;

            while (i < searchWord.size() && file.get(ch) && ch == searchWord[i]) 
            { 
                i++; 
            }

            if (i == searchWord.size()) 
            {
                if (replacementWord.size() <= searchWord.size()) 
                {
                    file.seekp(currentPos - searchWord.size());
                    file.write(replacementWord.c_str(), replacementWord.size());
                    int padding = searchWord.size() - replacementWord.size();
                    for (int j=0; j<padding; j++) 
                    {
                        file.put(' ');
                    }
                    file.seekg(currentPos);
                }
            } 
            else 
            {
                file.seekg(currentPos - searchWord.size() + 1);
            }
        }
    }
    file.close();

    cout << "\nUpdated file content:\n";
    file.open("data.txt", ios::in);
    if (!file) 
    {
        cout << "Error in opening file for reading" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) 
    {
        cout << line << endl;
    }
    file.close();
}