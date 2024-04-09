
/*
    Given two binary strings a and b, return their sum as a binary string.

    Example 1:
    Input: a = "11", b = "1"
    Output: "100"
    
    Example 2:
    Input: a = "1010", b = "1011"
    Output: "10101"

    Constraints:

    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ReversArray(char *);
char * addBinary(char*, char *);
int main(void)
{
    char *str1 = "010011";
    char *str2 = "100110";
    printf("number = %s\n", addBinary(str1,str2));
    return 0;
}

void ReversArray(char *str)
{
    int temp;
    int len  = strlen(str);
    printf("string befour reversing = %s\n", str);
    for(int i = 0; i < (len/2); i++)
    {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
     printf("string after reversing = %s\n", str);
}
char* addBinary(char* a, char* b) 
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b; // Determine the maximum length
    int curry = 0; 
    char *result = (char*)malloc(sizeof(char) * max_len+2);
    int i = 0;
    while((i < len_a) || (i < len_b))
    {
        int digit_a = i < len_a ? a[len_a - i - 1] - '0' : 0; // Convert char to int
        int digit_b = i < len_b ? b[len_b - i - 1] - '0' : 0; // Convert char to int 

        int total = digit_a + digit_b + curry;
        result[i++] = (total % 2)+48;
        curry = total/2;
    }
    if(curry)
    {
        result[i++] = '1';
    }
    result[i] = '\0';
    ReversArray(result);
    return result ;
}