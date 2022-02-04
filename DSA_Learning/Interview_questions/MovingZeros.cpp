/*Given an integer array of numbers, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]*/


#include <iostream>
#include<vector>
using namespace std;
/*void MoveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}*/
/*
void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    // If the current element is not 0, then we need to
    // append it just in front of last non 0 element we found. 
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
 	// After we have finished processing new elements,
 	// all the non-zero elements are already at beginning of array.
 	// We just need to fill remaining array with 0's.
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
*/
void MoveZeroes(vector<int>& nums) 
    {
        size_t len=nums.size();
        int index=0;
        for (int i=0; i<len-1; i++)
        {
            if (nums[i]==0 && nums[i+1]!=0)
            {
               swap(nums[index],nums[i+1]);
                index++;
            }
            else if(nums[i]!=0 && nums[i+1]==0)
            {
                index=i+1;
            }
        }
        for (int i=0; i<len; i++)
        {
          cout<<nums[i] <<" ";
        }     
    }
int main()
{
  vector<int> Numbers={0,1,0,3,12};
  MoveZeroes(Numbers);
  return 0;
}
