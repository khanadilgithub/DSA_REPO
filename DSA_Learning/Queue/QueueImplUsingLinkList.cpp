/*Queue implimentation using the the Linked list*/

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
class Queue
{
public:
    Queue()
    {
      m_head=NULL;
      m_tail=NULL;
    }
    // function to push data into queue 
    void Enqueue(int data)
    {
      Node* NewNode= new Node(data);
      if (m_head==NULL && m_tail==NULL)
      {
        m_head=NewNode;
        m_tail=NewNode;
      }
      else 
      {
        m_tail->m_next=NewNode;
        m_tail=NewNode;
      }
      
    }
    // function Deque the first element
    void Dequeue()
    {
      // checking whether the queue is empty or not
      if (m_head==NULL && m_tail==NULL)
      {
        cout << "Warning: Queue is Empty." << endl;
          return;
      }
      // if not empty display the top element & delete it
      cout <<"Info: Dequed Element: "<<m_head->m_data<< endl;
      Node* temp=m_head;
      m_head=temp->m_next;
      delete temp;
    }
    // function used to peek onto the last inserted element
    void peek()
    {
      // checking if queue is empty
      if(m_head==NULL && m_tail==NULL) 
      {
        cout << "Warning : Stack is Empty";
        return;
      }
      cout <<"Last Inserted Element is: "<<m_tail->m_data<<endl;
    }
    void display()
    {
      // if queue is empty then return
      if(m_head==NULL && m_tail==NULL)
      {
        cout << "Warning : Stack is Empty"<<endl;
        return;
      }
      Node* temp=m_head;
      while(temp!=NULL)
      {
        cout<<temp->m_data<<endl;
        temp=temp->m_next;
      }
      cout<<"======="<<endl<<endl;
    }
private:
  // declaring values
  Node* m_head;
  Node* m_tail;
};

int main()
{
  Queue q;
  q.Enqueue(12);
  q.Enqueue(11);
  q.Enqueue(13);
  q.Enqueue(33);
  q.Enqueue(02);
  q.display();
  q.Dequeue();
  q.display();
  q.Enqueue(24);
  q.display();
  q.peek();
}
