/*
In a given array find the first recurring charector 
Exp1: Array= [2,5,1,2,3,5,1,2,4]
Expected output: 2

Exp2: Array =[2,1,1, 2, 3,5,1,2,4]
Expected output: 1

Exp3: Array=[2,3,4,5]
Expected Output: None
*/

#include<iostream>
#include<set>
using namespace std;

int main(void)
{
  int arr[] = {2,5,1,2,3,5,1,2,4};
  int size=sizeof(arr)/sizeof(arr[0]);
  set<int> DataSet;
  int result=-1;
  for(int i=0; i<size; i++)
  {
      if (!DataSet.insert(arr[i]).second)
      {
        result=arr[i];
        break;
      }
  }
  if (result) cout<<result;
  else cout<<"NO recurring element";
  return 0;   
}
