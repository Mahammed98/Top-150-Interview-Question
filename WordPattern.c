#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
unsigned long long HashFunction(char*);
bool wordPattern(char*, char*);
bool linearsearch(unsigned long long, int *, int );



int main(void)
{
    char *s1 = "abba";
    char *s2 = "dog cat cat dog";

    printf("result = %d\n", wordPattern(s1, s2));
    return 0;
}

// hash function 
unsigned long long HashFunction(char* str)
{
    int i = 0;
    unsigned long long result = 0;
    while(str[i] != '\0')
    {
        result += str[i];
        result *= str[i];
        i++;
    }
    return (result + i);
}
// linear search function using linear search algorithm
bool linearsearch(unsigned long long Local_value, int *arr, int len)
{
    bool result = 0;  
    for(int j = 0; j < len; j++)
    {
        if(arr[j] == Local_value)
        {
            result = 1;
            break;
        }
    }
    return result;
}

/*

    1- check if space is found, this mean that substring is found
        - store this substring on the array called store
        - and this array will be the input of hash function and store the output hash in Hashvalue 
            - check to an each character on pattern string, if one of them were exist or not, in addition to if hash value were exist and matched to onther character or not
                (we store each new hashvalue on Store array)
            - if character is exist befour, and it deosn't match to its hashvalue, so flag = 0 and break from loop
              (S doesn't follow the same pattern)
        - else, still iterate until space is found

*/                                  
bool wordPattern(char* pattern, char* s) 
{
    unsigned long long *Map = (unsigned long long*)calloc(26, sizeof(unsigned long long));
    char ptr[30000] = {0} ;
    int Store[50] = {0};
    int PatternIter = 0, SIter = 0, PtrIter = 0;
    bool flag = 1;
    int SLen = strlen(s), PatternLen = strlen(pattern), i = 0;
    unsigned long long HashValue;

    while((SIter <= SLen) && (pattern[PatternIter] != '\0'))
    {
        if(s[SIter] == ' ' || s[SIter] == '\0')
        {
            ptr[PtrIter] = '\0';
            HashValue = HashFunction(ptr);
            if(Map[pattern[PatternIter]-97] == 0 && (!linearsearch(HashValue, Store, i)))
            {
                Map[pattern[PatternIter]-97] = HashValue;
                Store[i++] = HashValue;
            }
            else
            {
                if(Map[pattern[PatternIter]-97] != HashValue)
                {
                    flag = 0;
                    break;
                }
            }

            PatternIter++;
            ptr[0] = '\0';  // clear array 
            PtrIter = 0;   // reset iteration of arrat ptr
        }
        else
        {
            ptr[PtrIter++] = s[SIter];
        }
        SIter++;
    }

/*
    chech if number of patterns(each character) don't match to the number of substrings
*/
    if(PatternIter < PatternLen || SIter < SLen)
    {
        flag = 0;
    }

    free(Map);
    return flag;
}