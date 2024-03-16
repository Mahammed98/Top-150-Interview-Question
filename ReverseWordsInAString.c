#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char* reverseWords(char*);
int main(void)
{
    char str[20] = "a good  example";
    printf("string after modification =%s:\n",reverseWords(str));
    return 0;
}

char* reverseWords(char* s) 
{
    int i = strlen(s)-1;
    char*ptr = (char *)malloc(sizeof(char) * 10000);
    int j = 0, k = 0;

    while(i >= 0)
    {
        /*
            if the character is pointed and previous element was a space, then this is true condition
        */
        if(((s[i] != '\0') && (s[i] != ' ')) && ((i == 0) || (s[i-1] == ' ')))
        {
            j = i;          //storing the last value of pointed element

            while(s[j] != '\0' && s[j] != ' ')
            {
                ptr[k++] = s[j++];  // copy characters on the array until null terminator or space is found
            }
            ptr[k++] = ' ';  //put space after each word
        }
        else
        {
            //nothing
        }
        i--;
    }
   
    ptr[--k] = '\0';   //put null terminator

    return ptr;
    
}
