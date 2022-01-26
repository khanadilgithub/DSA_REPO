#include<iostream>
#include<vector>
/* Given an integer array numbers, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.*/

int maxSubArray(std::vector<int>& numbers) {
        int maxSum = numbers[0];
        int currSum = 0;
        int n = numbers.size();
        for(int i=0;i<n;i++){
            currSum += numbers[i];
            if(currSum > maxSum) maxSum = currSum;
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }

int main()
{
  std::vector<int> numbers={-2,1,-3,4,-1,2,1,-5,4};
  int SubArrSum=maxSubArray(numbers);
  std::cout<<SubArrSum;
  return 0;
}
