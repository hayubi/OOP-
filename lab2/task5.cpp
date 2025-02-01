/*Task 5) You are required to write a c++ function swap_string that shifts the last n characters of a string to the front n times. It will take str and int as parameters. And will return the new string after shifting.
Note: You have to work with pointers.
Output:
Enter a string: WELCOME
Enter the number of characters to shift: 2
Shifted string after shifting last two characters: MEWELCO

*/

#include <iostream>
#include <cstring>
using namespace std;

char* swap(char* userinput, int toShift);

int main()
{
    char userinput[50];
    cout << "Enter a string: ";
    cin.getline(userinput, 50);

    int toShift;
    cout << "Enter the number of characters to shift: ";
    cin >> toShift;

    char* result = swap(userinput, toShift);

    cout << "Shifted string after shifting last " << toShift << " characters: " << result << endl;

    delete[] result; 
}

char* swap(char* userinput, int toShift)
{
    int length = strlen(userinput);
    if (toShift >= length) 
        {return userinput;}

    char* temp = new char[length+1];
    for (int i=0; i<toShift; i++) 
    {
        temp[i] = userinput[length - toShift + i];
    }

    for (int i=0; i < length-toShift; i++) 
    {
        temp[toShift + i] = userinput[i];
    }

    temp[length] = '\0';
    return temp;
}
