// stack Implimentation using Link LIst

#include <bits/stdc++.h>
using namespace std;
class Node
{ 
public:
  Node(int& data):m_data(data), m_next(NULL)
  { 
  }
  int m_data;
  Node* m_next;
};
class Stack
{
public:
    Stack()
    {
      m_top=NULL;
    }
    // function to push data into stack of link list
    void push(int data)
    {
      Node* NewNode= new Node(data);
      if (m_top==NULL)
      {
        m_top=NewNode;
      }
      else 
      {
        NewNode->m_next=m_top;
        m_top=NewNode;
      }
      
    }
    // function pops the top most element
    void pop()
    {
      // checking whether the stack is empty or not
      if (m_top==NULL)
      {
        cout << "Warning: Stack is Empty." << endl;
          return;
      }
      // if not empty display the top element & delete it
      cout <<"Info: Popped Element: "<<m_top->m_data<< endl;
      Node* temp=m_top;
      m_top=temp->m_next;
      delete temp;
    }
    // function used to peek onto the top most element
    void peek()
    {
      // checking if stack is empty
      if(m_top==NULL) 
      {
        cout << "Warning : Stack is Empty";
        return;
      }
      cout <<"Top Most Element is: "<<m_top->m_data<<endl;
    }
    void display()
    {
      // if stack is empty then else block is executed
      if(m_top==NULL)
      {
        cout << "Warning : Stack is Empty"<<endl;
        return;
      }
      Node* temp=m_top;
      while(temp!=NULL)
      {
        cout<<temp->m_data<<endl;
        temp=temp->m_next;
      }
      cout<<"======="<<endl<<endl;
    }
private:
  // declaring values
  Node* m_top;
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
  St.peek();
}
