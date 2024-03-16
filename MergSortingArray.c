#include <stdio.h>
#include <stdlib.h>


void merge(int* nums1, int m, int* nums2, int n) 
{
   int a = m-1;
   int b = n-1;
   int c = (m+n)-1;

   while(b >= 0)
   {
       if((nums1[a] > nums2[b]) && (nums1[c] == 0))
       {
           nums1[c--] = nums1[a--];
       }
       else 
       {
           nums1[c--]= nums2[b--];
       }
   }
}

int main(void)
{
    int a1[] = {4,5,6,0,0,0};
    int a2[] = {1,2,3};
    merge(a1,3,a2,3);

    for(int i = 0; i < 6; i++)
    {
        printf("%d ", a1[i]);
    }
    printf("\n");


    return 0;
}