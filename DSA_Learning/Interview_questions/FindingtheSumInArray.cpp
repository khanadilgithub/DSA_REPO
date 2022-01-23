/* Problem - given an ORDERED integer array return the pair of numbers whose sum
add to some number k if not found return false.
input array = [1,2,3,9], sum = 8
output false, false
input array = [1,2,4,4], sum = 8
output 4, 4
Note: we cannot have pairs of same index numbers.
*/

#include <iostream>
#include<tuple>
#include<set>

/* Using naive approach O(n^2) time complexity and O(1) space complexity. */
std::tuple<int, int>FindSumPairs(int* arr, int size, int sum)
{
  for(int i = 0; i < size-1; i++)
  {
    for(int j = i + 1; j < size; j++)
    {
      if((arr[i] + arr[j]) == sum )
      {
        return std::make_tuple(arr[i], arr[j]);
      }
    }
  }
  return std::make_tuple(false, false);
}

/* Using better approach that takes the concept that array is ordered. O(sizeOfArr) time complexity*/
std::tuple<int, int>BetterFindSumPairs(int *arr, int size, int sum) 
{
  int low = 0, high = size-1;
  while(low < high)
  {
    int temp = arr[low] + arr[high];
    if(temp > sum)
    {
      high--;
    }
    else if(temp < sum)
    {
      low++;
    }
    else 
    {
      return std::make_tuple(arr[low], arr[high]);
    }
  }
  return std::make_tuple(false, false);
}

/*3. Till now we had assume that array is sorted now if remove that constraints the how to take that approach
method 1: again with naive approach discussed earlier.
method 2: using a data structure called set that will keep the track of all the visited numbers in array.
we are using set because it helps in maintaining integrity.
*/

std::tuple<int, int>UnsortedArrayFindSumPairs(int *arr, int size, int sum)
{
  std::set<int>comp;
  for(int i = 0; i < size; i++)
  {
    int target = sum - arr[i];
    if(comp.find(target) != comp.end()) 
    {
      return std::make_tuple(arr[i], target);
    }
    comp.insert(arr[i]);
    }
    return std::make_tuple(false, false);
}

int main() {
    int arr1[] = {1,2,3,9}, x, y;
    int arr2[] = {1,2,4,4}, sum = 8;
    int arr3[] = {1,2,4,5,0,2,6};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int size3 = sizeof(arr3)/sizeof(arr3[0]);
//Naive method testing
    std::tie(x, y) = FindSumPairs(arr1, size1, sum);
    std::cout<<"Naive Method Case1: The Pair is: "<<x<<", "<<y<<std::endl;
    std::tie(x, y) = FindSumPairs(arr2, size2, sum);
    std::cout<<"Naive Method Case2: The Pair is: "<<x<<", "<<y<<std::endl;
    std::tie(x, y) = FindSumPairs(arr3, size3, sum);
    std::cout<<"Naive Method Case3: The Pair is: "<<x<<", "<<y<<std::endl;
//Better method testing
    std::tie(x, y) = BetterFindSumPairs(arr1, size2, sum);
    std::cout<<"Better Method Case1: The Pair is: "<<x<<", "<<y<<std::endl;
    std::tie(x, y) = BetterFindSumPairs(arr2, size2, sum);
    std::cout<<"Better Method Case2: The Pair is: "<<x<<", "<<y<<std::endl;
    std::tie(x, y) = BetterFindSumPairs(arr3, size3, sum);
    std::cout<<"Better Method Case3: The Pair is: "<<x<<", "<<y<<std::endl;
//Unsorted Array Method
    std::tie(x, y) = UnsortedArrayFindSumPairs(arr1, size2, sum);
    std::cout<<"Unsorted Method Case1: The Pair is: "<<x<<", "<<y<<std::endl;
    std::tie(x, y) = UnsortedArrayFindSumPairs(arr2, size2, sum);
    std::cout<<"Unsorted Method Case2: The Pair is: "<<x<<", "<<y<<std::endl;
    std::tie(x, y) = UnsortedArrayFindSumPairs(arr3, size3, sum);
    std::cout<<"Unsorted Method Case3: The Pair is: "<<x<<", "<<y<<std::endl;
    return 0;
}
