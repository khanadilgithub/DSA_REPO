
/*
Implimentation od singly lineked list 
with following method 
1. push_back();
2. pop_back();
3. Insert(arg1, arg2);
4. Delete(arg1);
*/

#include<iostream>
using namespace std;
// Node of list
class Node
{
public:
  int m_data;
  Node* m_next;
  Node(const int& value)
  :m_data(value),m_next(NULL)
  {}
};
//LinkLst data structure 
class LinkList
{
public:
  Node* m_head;//head Node 
  Node* m_tail;//tail Node
  int m_numelm=0;//No of element to know the size
//push back method
  void push_back(const int& elm)
  {
    Node* NewNode= new Node(elm);
    if (m_head==NULL)
    {
      m_head=NewNode;
      m_tail=NewNode;
      m_numelm++;
    }
    else
    {
      m_tail->m_next=NewNode;
      m_tail=NewNode;
      m_numelm++;
    }
  }
//method to inset an elemet at given position
  void insert(const int& elm, const int& n)
  {
    if (n>(m_numelm+1))
    {
      cout<<"Invalid input \n";
      return;
    }
    Node* NewNode =new Node(elm);
    Node* temp =m_head;
    if (m_head==NULL)
    {
      cout<<"list is emplty";
      return;
    }
    else
    {
      if (n==1)
      {
        NewNode->m_next=m_head;
        m_head=NewNode;
        m_numelm++;
        return;
      }
      for (int i=1;i<n-1; i++)
        {
          temp=temp->m_next;
        }
      NewNode->m_next=temp->m_next;
      temp->m_next=NewNode;
      m_numelm++;
    } 
  }
//method to delete the last element
  void pop_back()
  {
    if (m_head==NULL)
    {
      cout<<"list is emplty";
      return;
    }
    else
    {
      Node* temp;
      Node* prevs;
      temp=m_head;
      if (m_numelm==1)
      {
        m_head=temp->m_next;
        delete temp;
        return;
      }
      while(temp->m_next!=NULL)
        {
          prevs=temp;
          temp=temp->m_next;
        }
      {
      prevs->m_next=NULL;
      m_tail=prevs;
      delete temp;
      }
      m_numelm--;
    }
  }
//method to get the size of list
int Size()
{
  return m_numelm;
}
//method to print the hole list
void printlist()
{
  Node* temp=m_head;
  if (m_head==NULL)
  {
    cout<< "list become empty"; return;
  }
  for(int i=0; i<m_numelm; i++)
  {
    cout<<temp->m_data<<"->";
    temp=temp->m_next;
  }
  cout<<"null \n";
}
//method to delete desired element of list
void Delete(const int& n)
 {
    if (n>m_numelm)
    {
      cout<<"Invalid input";
      return;
    }
    Node* Prevs =m_head;
    Node* CrntNode;
    if (m_head==NULL)
    {
      cout<<"list is emplty";
      return;
    }
    else
    {
      if (n==1)
      {
        m_head=Prevs->m_next;
        delete Prevs;
        m_numelm--;
        return;
      }
      for (int i=1;i<n-1; i++)
        {
          Prevs=Prevs->m_next;
        }
      CrntNode=Prevs->m_next;
      Prevs->m_next=CrntNode->m_next;
      delete CrntNode;
      m_numelm--;
   }
 }
};
int main(void)
{
  LinkList lnlst;//link list object
  lnlst.push_back(1);
  lnlst.push_back(3);
  lnlst.push_back(4);
  lnlst.push_back(5);
  lnlst.push_back(6);
  lnlst.printlist();
  lnlst.insert(0,1);
  lnlst.insert(2,3);
  lnlst.insert(7,8);
  lnlst.insert(8,9);
  lnlst.printlist();
  lnlst.pop_back();
  lnlst.printlist();
  lnlst.Delete(8);
  lnlst.printlist();
  cout<<"Size of list is: "<<lnlst.Size()<<endl;
  return 0;   
}
