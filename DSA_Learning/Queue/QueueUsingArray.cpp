/*Queue implimentation using Array*/

#include <bits/stdc++.h>
using namespace std;
//size of the queue
#define m_size 101 
class Queue
{
public:
//constructor
Queue()
{
  m_front=-1;
  m_back=-1;
  m_length=0;
}
//Enque Method
void Enque(int val)
{
  cout<<"Queueing: "<<val<<endl;
  if (IsEmpty())
  {
    m_front=0;
    m_back=0;
  }
  else if (IsFull())
  {
    cout<<"Queue is Full"<<endl;
  }
  else
  {
    m_front=((m_front+1)%m_size);
  }
  m_arr[m_front]=val;
  m_length++;
}
//Dequeue method
void Deque()
{
  if (IsEmpty())
  {
    cout<<"Queue is empty, Can not deque"<<endl;
    return;
  }
  else if (m_front==m_back-1)
  {
    m_front=m_back=-1;
    m_length--;
    return;
  }
  cout<<"Dequeing: "<<m_arr[m_back]<<endl;
  m_back=((m_back+1)%m_size);
}
//printing in the order of inserted
void Print ()
{
  int i=m_back;
  while(i-1!=m_front)
    {
      cout<<m_arr[i]<<" ";
      i=((i+1)%m_size);
    }
  cout<<endl;
}
//size of the queue
int Size()
{
  return m_length;
}
private:
int m_arr[m_size];
int m_front;
int m_back;
int m_length;
//Check for Empty
bool IsEmpty()
{
  if (m_front==-1 && m_back==-1)
  {
    return true;
  }
  return false;
}
//check for Full
bool IsFull()
{
  if (((m_front+1)%m_size)==m_back)
  {
    return true;
  }
  return false;
}
};
int main()
{
  Queue q;
  q.Enque(0);
  q.Enque(1);
  q.Enque(2);
  q.Enque(3);
  q.Print();
  q.Deque();
  q.Deque();
  q.Print();
  q.Enque(4);
  q.Enque(5);
  q.Deque();
  q.Enque(6);
  q.Deque();
  q.Enque(7);
  q.Enque(8);
  q.Print();
  q.Size();
}
