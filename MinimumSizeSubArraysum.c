#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int minSubArrayLen(int , int* , int ); 

int main(void)
{
    int arr[] = {5,1,3,5,10,7,4,9,2,8};
    printf("minimum size  =%d:\n",minSubArrayLen(15,arr,(sizeof(arr)/sizeof(arr[0]))));
    return 0;
}


// time complexity O(n^2)
/*int minSubArrayLen(int target, int* nums, int numsSize) 
{
    long long int *dp = (int *)calloc(numsSize, sizeof(int));
    int flag = 0;
    int result = 0;
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = 0; j < (numsSize - i); j++)
        {
            dp[j] += nums[j+i];
            if(dp[j] >= target)
            {
                flag = 1;
                result = i+1;
                break;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
    return result;
}*/

// time complexity o(n)
// used sliding window technique  https://www.youtube.com/watch?v=aYqYMIqZx5s
int minSubArrayLen(int target, int* nums, int numsSize) 
{
   int left = 0, right = 0;
   long long int sum = 0;
   int NumberOfSubArrayEle = numsSize+1;

   for(right; right < numsSize;)
   {
        sum += nums[right++];
        while(sum >= target)
        {
            NumberOfSubArrayEle = (NumberOfSubArrayEle < (right-left) ? NumberOfSubArrayEle : (right-left)); 
            sum -= nums[left++];
        }
   }
   return NumberOfSubArrayEle % (numsSize+1);
}

