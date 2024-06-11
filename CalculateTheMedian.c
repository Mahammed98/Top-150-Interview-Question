double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int * arr = (int*)malloc((nums1Size+nums2Size) * sizeof(int));
    int i = 0;
    int NI1 = 0, NI2 = 0;
    double result = 0.0;

    /*
        first we are gonna merge the 2 arrays, in ascending order 
    */
    while(NI1 < nums1Size || NI2 < nums2Size)
    {
        if(NI1 == nums1Size)
        {
            arr[i++] = nums2[NI2++];
        }    
        else if(NI2 == nums2Size)
        {
            arr[i++] = nums1[NI1++];
        }
        else if(nums1[NI1] < nums2[NI2])
        {
            arr[i++] = nums1[NI1++];
        }
        else if(nums1[NI1] > nums2[NI2])
        {
            arr[i++] = nums2[NI2++];
        }
        else
        {
            arr[i++] = nums1[NI1++];
            arr[i++] = nums2[NI2++];
        }
    }
    /*  
        calcualte the midian 
    */
    if(i % 2 == 0)
    {
        result = ((double)arr[i/2] + arr[(i/2)-1]) / 2;
    }
    else 
    {
        result = arr[i/2];
    }
    return result ;
}