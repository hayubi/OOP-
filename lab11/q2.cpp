#include <iostream>
using namespace std;

class StackOverflowException : public exception
{
    public: 
        const char* what() const noexcept override
        {
            return "StackOverflowException - Stack is full";
        }
};

class StackUnderflowException : public exception
{
    public: 
        const char* what() const noexcept override
        {
            return "StackUnderflowException - Stack is empty";
        }
};

template <typename T, int capacity> //typename,,not class
class Stack
{
    private:
        T array[capacity];
        int topindex;

    public:
        Stack(int t = -1) : topindex(t) {}

        void push(T value)
        {
            if (topindex > capacity-1)
            {
                throw StackOverflowException();
            }
            array[++topindex] = value;
            cout << "Pushed " << value << " successfully" << endl;
        }

        T pop()
        {
            if (topindex < 0)
            {
                throw StackUnderflowException();
            }
            return array[topindex--];
        }
};

int main()
{
    Stack<int,4> stack; //5 numbers array

    try
    {
        stack.push(10);
        stack.push(33);
        stack.push(22);
        stack.push(88);
        stack.push(77);
        stack.push(66);
        stack.pop();
        stack.pop();
        stack.pop();
        stack.push(45);
    }
    catch(const StackOverflowException& oe)
    {
        cout << "Pushing to a full stack: " << oe.what() << endl;
    }
    catch(const StackUnderflowException& ue)
    {
        cout << "Popping from an empty stack: " << ue.what() << endl;
    }
    catch(const exception& e)
    {
        cout << "Some exception occurred" << endl;
    }
}
