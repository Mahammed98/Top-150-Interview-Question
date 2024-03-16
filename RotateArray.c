void revers(int*arr, int start, int end)
{
    int temp;
    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k) 
{
    k %= numsSize;   // if number of rotations exceed number of elements
    //ex [1,2,3,4,5,6,7] -> k = 3 (number of rotations), desird output = [5,6,7,1,2,3,4]
    revers(nums, numsSize-k, numsSize-1);   // reverse second part  [5,6,7]
    revers(nums, 0, numsSize-k-1);            //reverse first part [1,2,3,4]
    revers(nums, 0, numsSize-1);            //reverse all parts after modified array
}

// code below is not optimal is has O(n2), not efficetiant with big arrays

/*void rotate(int* nums, int numsSize, int k) 
{
    int temp;
    k %= numsSize;
    while(k--)
    {
        temp = nums[numsSize-1];
        for(int i = numsSize-2; i >= 0; i--)
        {
            nums[i+1] = nums[i];
        }
        nums[0] = temp;
    }   
}*/