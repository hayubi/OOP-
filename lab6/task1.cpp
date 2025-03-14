/*TASK # 01: You are required to implement a simple message handling system using object-oriented
programming in C++.
Task Breakdown:
1. Create a Message class
    o It should have a private instance variable text of type string to store the message
    content.
    o Implement a method toString() that returns the message text.
    o Provide a setter method to modify the text value.
2. Create an SMS class that inherits from Message
    o It should have an additional instance variable recipientContactNo to store the
    recipient’s phone number.
    o Implement appropriate accessor and mutator methods.
    o Override the toString() method to return a concatenated string containing the
    recipient’s contact number and the message text.
3. Create an Email class that inherits from Message
    o It should have additional instance variables: sender, receiver, and subject.
    o Implement appropriate accessor and mutator methods.
    o Override the toString() method to return a concatenated string containing sender,
    receiver, subject, and the message text.
4. Implement Keyword Search Function
    o Define a function:
    o bool ContainsKeyword(const Message& messageObject, const string& keyword);
    o This function should return true if the text of the Message object contains the
    given keyword, otherwise return false.
5. Implement Message Encoding
    o Define a function to encode a given message using the following scheme:
     Each character should be replaced by the next character in the alphabet
    (e.g., ‘A’ → ‘B’, ‘b’ → ‘c’, ‘Z’ → ‘A’, ‘z’ → ‘a’).
    Example: If the message is "This is Java", the encoded message should be
    "Uijt jt Kbwb".
6. Test the Implementation
    o In the main() function, create sample objects of SMS and Email, assign values,
    and test the functionalities including keyword search and encoding.*/

#include <iostream>
#include <string>
using namespace std;

class Message
{
    private:
        string text;
    
        public:
            Message() 
            {
                text = "";
            }
            Message(string t) : text(t) {}

            virtual string toString() const
            {
                return text;
            }
            virtual ~Message() {}

            void setText(string t) { text = t; }
};

class SMS : public Message
{
    private:
        string recipientContactNo;

    public:
        SMS(string t, string contact) : Message(t), recipientContactNo(contact) {}

        void setContact(string contact) { recipientContactNo = contact; }
        string getContact() const { return recipientContactNo; }

        string toString() const override
        {
            string newstring = recipientContactNo + " " + Message::toString();
            return newstring;
        }
};

class Email : public Message
{
    private:
        string sender;
        string receiver;
        string subject;
    
    public:
        Email(string t, string s, string r, string sub) : Message(t), sender(s), receiver(r), subject(sub) {}

        void setSender(string s) { sender = s; }
        void setReceiver(string r) { receiver = r; }
        void setSubject(string sub) { subject = sub; }

        string getSender() const { return sender; }
        string getReceiver() const { return receiver; }
        string getSubject() const { return subject; }

        string toString() const override
        {
            string newstring = sender + " " + receiver + " " + subject + " " + Message::toString();
            return newstring;
        }
};

//global functions
bool ContainsKeyword(const Message& messageObject, const string& keyword)
{
    return (messageObject.toString().find(keyword) != string::npos);
}

string encode(Message& messageObject)
{
    string word = messageObject.toString();
    for (int i=0; i<word.length(); i++)
    {
        char& c = word[i];
        if (c >= 'A' && c <= 'Z')
        {
            if (c == 'Z')
                c = 'A';
            else
                c++;
        }
        else if (c >= 'a' && c <= 'z')
        {
            if (c == 'z')
                c = 'a';
            else
                c++;
        }
    }
    return word;
}

int main()
{
    SMS sms("This is Java", "03306945851");
    cout << "Original SMS: " << sms.toString();
    cout << endl;
    string keyword1 = "hello";
    if (ContainsKeyword(sms, keyword1)) //how to use global functions--dont start with object.function()
        cout << " 'hello' found in sms" << endl;
    else
        cout << " 'hello' not found in sms" << endl;

    string keyword2 = "Java";
    if (ContainsKeyword(sms, keyword2))
        cout << " 'Java' found in sms" << endl;
    else
        cout << " 'Java' not found in sms" << endl;

    string encoded1 = encode(sms);
    cout << "Encoded SMS: " << encoded1 << endl;
    cout << endl;
    
    Email email("I hope this email finds you well.", "hafsa@gmail.com", "marium@gmail.com", "Subject");
    cout << "Original Email: " << email.toString();
    cout << endl;
    string keyword3 = "how";
    if (ContainsKeyword(email, keyword3))
        cout << " 'how' found in email" << endl;
    else
        cout << " 'how' not found in email" << endl;

    string keyword4 = "well";
    if (ContainsKeyword(email, keyword4))
        cout << " 'well' found in email" << endl;
    else
        cout << " 'well' not found in email" << endl;

    string encoded2 = encode(email);
    cout << "Encoded Email: " << encoded2 << endl;
}
