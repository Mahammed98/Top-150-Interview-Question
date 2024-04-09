/*
    Given an integer array nums and an integer k, return the kth largest element in the array.

    Note that it is the kth largest element in the sorted order, not the kth distinct element.

    Can you solve it without sorting?
 

    Example 1:
    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5

    Example 2:
    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4
    
    Constraints:

    1 <= k <= nums.length <= 105
    -104 <= nums[i] <= 104

*/
int findKthLargest(int* nums, int numsSize, int k) 
{
    int PositivArr [10001] = {0};
    int NegativeArr [10001] = {0};
    int greatest = 0;
    int result = 0;
    bool flag = 0;

    // calculate the frequancy for each positive and negative elements
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] >= 0)
        {
            PositivArr[nums[i]]++;
        }
        else
        {
            NegativeArr[abs(nums[i])]++;
        }
    }

    for(int i = 10000; i >= 0; i--)
    {
        greatest += PositivArr[i];
        if(greatest >= k)
        {
            result = i;
            flag = 1;
            break;
        }
    }
    if(!flag) // if we didn't find the number in the positive part
    {
        for(int i = 1; i <= 10001; i++)
        {
            greatest += NegativeArr[i];
            if(greatest >= k)
            {
                result = -i ;
                break;
            }
        }
    }
    return result;
}
