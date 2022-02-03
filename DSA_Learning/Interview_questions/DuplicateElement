/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct. 

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include <iostream>
#include<set>
#include<vector>

bool ContainsDuplicate(std::vector<int>& nums) 
    {
        std::set<int> NumSet;
        for(int elm:nums)
        {
         if(!NumSet.insert(elm).second)
         {
             return true;
         }
        }
        return false;
    }

/*bool ContainsDuplicate(std::vector<int>& nums) 
    {
    sort(nums.begin(),nums.end());
			for(int i=1;i<nums.size();i++)
      {
				if(nums[i]==nums[i-1])
					return true;
      }
			return false;
    }
*/
/*
bool ContainsDuplicate(vector<int>& nums) {
   		set<int> a;
   		for(auto &x:nums)
   		a.insert(x);
   		return (a.size()!=nums.size());
   }
*/
int main()
{
  std::vector<int> Numbers={0,1,0,3,12};
  if(ContainsDuplicate(Numbers))
  std::cout<<"Duplicate Element Found";
  else std::cout<<"NO Duplicate Element";
  return 0;
}
