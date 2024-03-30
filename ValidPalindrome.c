
/*
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

    

    Example 1:

    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
    Example 2:

    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.
    Example 3:

    Input: s = " "
    Output: true
    Explanation: s is an empty string "" after removing non-alphanumeric characters.
    Since an empty string reads the same forward and backward, it is a palindrome.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPalindrome(char* s) 
{
    int start = 0;
    int flag = 1;
    char * CopyString = (char*)malloc(sizeof(char) * (strlen(s)+1));
    int j = 0;
    while(s[start] != '\0')
    {
        if((s[start] >= 97 && s[start] <= 122)||(s[start] >= 48 && s[start] <= 57))
        {
            CopyString[j++] = s[start];
        }
        else if((s[start] >= 65 && s[start] <= 90))
        {
            CopyString[j++] = s[start]+32;
        }
        start++;
    }
    CopyString[j] = '\0';
    start = 0;
    j--;
     while(start <= j)
     {
        if((CopyString[start] != CopyString[j]))
        {
            flag = 0;
            break;
        }
        start++;
        j--;
     }
 
    free(CopyString);
    return flag;
}


int main(void)
{
    char *string = "0P";
    printf("value = %d", isPalindrome(string));
    return 0;
}
/*
bool isPalindrome(char* s) 
{
    int start = 0;
    int end = strlen(s) - 1;
    bool flag = true;
    while(start <= end)
    {
        if(((s[start] >= 65 && s[start] <= 90)||(s[start] >= 97 && s[start] <= 122)) && ((s[end] >= 65 && s[end] <= 90)||(s[end] >= 97 && s[end] <= 122)))
        {
            if((s[start] == s[end]) || (s[start] == s[end]+32) || (s[start] == s[end]-32))
            {
                flag = true;
                start++;
                end--;
            }
            else 
            {
                flag = false;
                break;
            }
        }
        else
        {
            
            if(((s[start] >= 65 && s[start] <= 90)||(s[start] >= 97 && s[start] <= 122)))
            {
                end--;
                flag = false;
            }
            else if(((s[end] >= 65 && s[end] <= 90)||(s[end] >= 97 && s[end] <= 122)))
            {
                start++;
                flag = false;
            }
            else
            {
                end--;
                start++;
            }
        }
    }
    return flag;
}
*/