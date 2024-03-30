/*
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

    

    Example 1:

    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]
    Example 2:

    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]
    

    Constraints:

    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) 
{
    int *prefix = (int *)malloc(sizeof(int) * numsSize);
    int *postfix = (int *)malloc(sizeof(int) * numsSize);
    int *res = (int *) malloc(sizeof(int) * numsSize);
    prefix[0] = 1;
    postfix[numsSize - 1] = 1;
    int value = 1;

    *returnSize = numsSize;
    /*
        calculate product of prefix for each element (product elements to left)
    */
    for(int i = 1; i < numsSize; i++)
    {
        value *= nums[i-1];
        prefix[i] = value;
    }
    value = 1; //reset value
    /*
        calculate product of postfix ro suffix for each element (product elements to right)
    */
    for(int i = numsSize-2; i >= 0; i--)
    {
        value *= nums[i+1];
        postfix[i] = value;
    }
    // Final result by multiplying prefix and postfix 
    for(int i = 0; i < numsSize; i++)
    {
        res[i] = prefix[i] * postfix[i];
    }
    free(postfix);
    free(prefix);

    return res;
}