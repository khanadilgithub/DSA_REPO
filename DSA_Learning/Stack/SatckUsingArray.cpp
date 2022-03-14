// stack using array

#include <bits/stdc++.h>
#define SIZE 100
using namespace std;

class Stack
{
public:
    // initailizing values
    Stack()
    {
        m_top = -1;
        m_arr = new int[SIZE];
    }

    // function to push data into stack-[array]
    void push(int data)
    {
        // Overflow check in case the limit exceeds
        if (m_top >= SIZE - 1)
        {
            cout << "Error: Stack Overflows" << endl;
            return;
        }
        // increment the counter and add the data
        m_top += 1;
        m_arr[m_top] = data;
    }

    // function pops the top most element
    void pop()
    {
        // checking whether the stack is empty or not
        if (m_top == -1)
        {
            cout << "Warning: Stack is Empty." << endl;
            return;
        }
        // if its not empty display the top element and decrement top by 1 to delete the top most data
        cout << "Info: Popped Element: " << m_arr[m_top] << endl;
        m_top--;
    }

    // function used to peek onto the top most element
    int peek()
    {
        // checking if stack is empty
        if(m_top < 0) {
            cout << "Warning : Stack is Empty";
            return 0;
        }
        return m_arr[m_top];
    }

    void display()
    {
        // looping over the stack conditionally
        if (m_top >= 0)
        {
            cout << "Stack Elements are: " << endl;
            for (int i = m_top; i >= 0; i--)
            {
                cout << m_arr[i] << endl;
            }
            cout << endl;
        }
        // if stack is empty then else block is executed
        else
        {
            cout << "Warning : Stack is Empty";
            return;
        }
    }
private:
    // declaring values
    int m_top;
    int* m_arr;
};

int main()
{
    Stack St;
    St.push(12);
    St.push(11);
    St.push(13);
    St.push(33);
    St.push(02);
    St.display();

    St.pop();
    St.display();

    St.push(24);
    St.display();

    cout << "Top Most Element is: " << St.peek() << endl;
}
