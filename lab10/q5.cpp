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

// Function to create and populate the file initially
void createFile() 
{
    ofstream fout("data.txt");
    fout << "AI is the future. AI will transform the world. Embrace AI now.";
    fout.close();
}

int main() 
{
    createFile();

    string searchWord, replacementWord;
    cout << "Enter word to search: ";
    cin >> searchWord;
    cout << "Enter word to replace it with: ";
    cin >> replacementWord;

    if (replacementWord.length() > searchWord.length()) {
        cout << "Replacement word must be equal or smaller in length than the search word." << endl;
        return 1;
    }

    fstream file("data.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    char ch;
    string temp="";
    streampos pos;
    while(file.get(ch))
    {
        //add to temp
        temp = temp + ch;

        if (temp.length() > searchWord.length())
        {
            temp.erase(0,1);
        }

        if (temp == searchWord)
        {
            pos = file.tellg();
            file.seekp(pos - searchWord.length());
            
            //overwrite
            for (int i=0; i<replacementWord.length(); i++)
            {
                file.put(replacementWord[i]);
            }

            //space dalo agar replacement short hai
            for (int i=replacementWord.length(); i<searchWord.length(); i++)
            {
                file.put(' ');
            }

            //reset temp takay agar aik file me searchword morethan 1 time ho,,,tou wo bhi replace hojaye
            temp = " "; 
            file.seekg(pos); //resume reading from after the replaced word
        }
    }
    file.close();

    //display updated file
    ifstream fin("data.txt", ios::in);
    if (!fin)
    {
        cout << "Error";
    }

    string line;
    while(getline(fin, line))
    {
        cout << line << endl;
    }
    file.close();
}











    /*char ch;
    string wordBuffer = "";
    streampos pos;
    while (file.get(ch)) {
        // Build word character-by-character
        wordBuffer += ch;

        // If wordBuffer size exceeds searchWord, drop oldest char
        if (wordBuffer.length() > searchWord.length())
            wordBuffer.erase(0, 1);

        // If a match is found
        if (wordBuffer == searchWord) {
            pos = file.tellg(); // Position AFTER the match
            file.seekp(pos - searchWord.length()); // Move write pointer to start of word

            // Overwrite with replacement word
            for (int i = 0; i < replacementWord.length(); ++i)
                file.put(replacementWord[i]);

            // Pad with spaces if replacement is shorter
            for (int i = replacementWord.length(); i < searchWord.length(); ++i)
                file.put(' ');

            wordBuffer = ""; // Reset buffer to avoid overlap
            file.seekg(pos); // Resume reading from after the replaced word
        }
    }

    file.close();

    // Display the updated file
    cout << "\nUpdated File Content:\n";
    ifstream fin("data.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();

    return 0;
}
