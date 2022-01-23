#include<iostream>
#include<cstring>
int* MergSortArray(int* arr1, int* arr2, int& size1, int& size2)
{
  int* MergArr = new int [size1+size2];

  int indx1=0, indx2=0, indx=0;

  while(indx1<size1 && indx2<size2)
  {
    if (arr1[indx1]<arr2[indx2])
    {
      MergArr[indx]=arr1[indx1];
      indx1++;
      indx++;
    }
    else
    {
      MergArr[indx]=arr2[indx2];
      indx2++;
      indx++;
    }
  }
  for( int i = indx1; i < size1; ++i)
  {
    MergArr[indx] = arr1[i];
    ++indx;
  }
  for( int j = indx2; j < size2; ++j)
  {
    MergArr[indx] = arr2[j];
    ++indx;
  }
  return MergArr;
}

int main()
{
    int arr1[] = {1,2,3,4,5,6,7};
    int arr2[] = {3,4,5,7,8,9,10, 11};

    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
  int* MrgArray=MergSortArray(arr1, arr2, size1,size2);
  for (int i=0; i<(size1+size2); i++)
  {
    std::cout<<MrgArray[i]<<",";
  }
  return 0;
}
