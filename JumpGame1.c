/*
    You are given an integer array nums. You are initially positioned at the array's first index, 
    and each element in the array represents your maximum jump length at that position.

    Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 105

*/
bool canJump(int* nums, int numsSize) 
{
    bool result;  
    int max = nums[0];
    int counter = 0;

    for(int i = 0; i < numsSize; i++)
    { 
        if((nums[i] + i) >= numsSize-1 || numsSize == 1) // if reached to the end or only one element is existed
        {
            result =  true;
            break;
        }
        if(counter >= max)  // end of interval
        {
            if(nums[i] != 0)  // if new maximum value is found 
            {
                max = nums[i];  
                counter = 0;  // reset counter new maximum value is found
            }
            else
            {
                result = false;
                break;
            }
        }
        else if(nums[i] >= max)   // (new interval) new maximum value is found within an current interval 
        { 
            max = nums[i];  
            counter = 0; // reset counter
        }
        
        counter++; 
    }
    return result;

}
