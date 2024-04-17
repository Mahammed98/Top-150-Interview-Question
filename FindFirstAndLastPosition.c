/*
        Given an array of integers nums sorted in non-decreasing order,
        find the starting and ending position of a given target value.
        If target is not found in the array, return [-1, -1].
        You must write an algorithm with O(log n) runtime complexity.


    Example 1:
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

    Example 2:
    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]

    Example 3:
    Input: nums = [], target = 0
    Output: [-1,-1]
    
    Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
    nums is a non-decreasing array.
    -109 <= target <= 109
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
    int *result = (int*)malloc(sizeof(int) * 2);
    result[0] = -1;
    result[1] = -1;
    int left = 0;
    int right = numsSize-1;
    int mid = 0;
    int start = 0, end = 0;
    while(left <= right)
    {
        mid = (left+right)/2;
        if(nums[mid] == target)
        {
            start = end = mid;
            while(1)                // find start
            {
                if(start == 0 || nums[start-1] != nums[mid])
                {
                    break;
                }               
                else
                {
                    start--;
                }
            }
            while(1)                // find end
            {
                if(end == numsSize-1 || nums[end+1] != nums[mid])
                {
                    break;
                }               
                else
                {
                    end++;
                }
            }
            result[0] = start;
            result[1] = end;
            break;                  // exit from main loop
        }
        else if(nums[mid] < target)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }

    *returnSize = 2;
    return result;
}