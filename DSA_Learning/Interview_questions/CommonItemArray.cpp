/* Given 2 arrays, create a function that let's a user know (true/false) whether these two arrays contain any common items
For Example:
const array1 = ['a', 'b', 'c', 'x'];
const array2 = ['z', 'y', 'i'];
should return false.
-----------
const array1 = ['a', 'b', 'c', 'x'];
const array2 = ['z', 'y', 'x'];
should return true.
2 parameters - arrays - no size limit
return true or false  */

#include <iostream>
#include<map>
/* defining a function for naive approach -> O(sizeA * sizeB) time complexity
                                          -> O(1) space complexity
*/
template<typename T>//using template to support all type of data
bool FindingPair(T* arrA, T* arrB, size_t& sizeA, size_t& sizeB) {
    if(sizeA == 0 && sizeB == 0) return true;
    else
     {
       for(int i = 0; i < sizeA; i++)
        {
          for(int j = 0; j < sizeB; j++) 
          {
            if(arrA[i] == arrB[j]) return true;

          }
        }
    }
    return false;
}

/* O(sizeA + sizeB) time complexity and  and O(sizeA) space complexity */

template<typename T>
bool BetterFindingPair(T *arrA, T *arrB, size_t& sizeA, size_t& sizeB)
{
    std::map<T, bool>Items;
    for(int i = 0; i < sizeA; i++)
     {
       Items.insert({arrA[i], true});//storing the element of array one into map
     }
    for(int i = 0; i < sizeB; i++)
    {
        if(Items.find(arrB[i]) != Items.end()) //searching for the element into the map
        {
            return true;
        }
    }
    return false;
}

int main() 
{

    char arrA[] = {'a', 'b', 'c', 'x'};
    char arrB[] = {'z', 'y', 'x'};

    size_t sizeA = sizeof(arrA)/sizeof(arrA[0]);
    size_t sizeB = sizeof(arrB)/sizeof(arrB[0]);

    if (FindingPair(arrA, arrB, sizeA, sizeB)) std::cout<<"Naive Method: Common Item Found"<<std::endl;
    else std::cout<<"Naive Method: No common Item"<<std::endl;
    if (FindingPair(arrA, arrB, sizeA, sizeB)) std::cout<<"Better Method: Common Item Found"<<std::endl;
    else std::cout<<"Better Method: No common Item"<<std::endl;
    return 0;
}
