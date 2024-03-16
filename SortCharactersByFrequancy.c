#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _SIZE_ 75   //(string from 0 to 9, A to Z, and a to z)
char* frequencySort(char* s) 
{
    int *fq = (int*)calloc(_SIZE_,sizeof(int));
    int i = 0, j = 0, k = 0;
    int len = strlen(s);
    int Number = 0;
    int max = 0;
    char *ptr = (char*)malloc(sizeof(char)*(len+1));
    int ptr_ite = 0;
    /*
        calculate number of frequancy of each element on the string
    */
    for(i = 0; i < len; i++)
    {
        fq[s[i] - 48]++; // 48 is the asc for 0 (string from 0 to 9, A to Z, and a to z)
    }
    for(i = 0; i < 75; i++)
    {
        printf("%d ", fq[i]);
    }
    printf("\n");
    
    /*
        calcualte no.of each element on string
    */
    for(i = 0; i < 75; i++)
    {
        if(fq[i] > 0)
        {
            Number++;
        }
    }
    for(i = 0; i < Number; i++)
    {  
        for(j = 0; j < 75; j++)
        {
            if(fq[j] > max)
            {
                max = fq[j];
                k = j;        
            }
        } 
        for(j = 0; j < max; j++)  // store characters in a new array 
            {
                ptr[ptr_ite++] = k + 48;
            }   
            fq[k] = 0;
            max = 0;
    }
    ptr[ptr_ite] = '\0';
    free(fq);
    return ptr;
}
int main(void)
{
    char str[] = "tree";
    printf("string = %s \n", frequencySort(str));
    return 0;
}