/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** summaryRanges(int* nums, int numsSize, int* returnSize) 
{
    int start = 0;
    int end = 0;
    int i = 0;
    *returnSize = 0;
    /*  first creat a 2d array dynamicaly */
    char **ptr = (char **)malloc(sizeof(char*) * 20);
    for(int x = 0; x < 20; x++)
    {
        ptr[x] = (char *)malloc(sizeof(char)*25);
    }
    // we use 2 pointer (start and end) to point the end and start of each interval
    for(end = 1; end < numsSize; end++)
    {
        if((long long int)nums[end] - nums[end-1] == 1)
        {
            continue;
        }
        else
        {
            if(start == end-1)
            {
                snprintf(ptr[i], 25, "%d",nums[start]);
            }
            else
            {
                snprintf(ptr[i], 25, "%d->%d", nums[start],nums[end-1]);
            }   
            start = end;      
            i++;
        }
    }
    // previous for loop doesn't process the last interval on array so,
    // we make a process individually  
    if(start == numsSize-1)
    {
        snprintf(ptr[i], 25, "%d",nums[start]);
        *returnSize = i+1;
    }
    else if (start < numsSize-1)
    {
        snprintf(ptr[i], 25, "%d->%d", nums[start],nums[numsSize-1]);
        *returnSize = i+1;
    }
    return ptr;
}