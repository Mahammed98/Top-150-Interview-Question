#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define max 7
int evalRPN(char tokens[][4], int tokensSize) 
{
    signed short int stack [1000] =  {0};
    signed short int top = 0;
    int result = 0;
    for(int i = 0; i < tokensSize; i++)
    {
        switch (tokens[i][0])
        {
            case '+':
                result = stack[top-2] + stack[top-1];
                stack[top-2] = result;
                top--;
                break;
            case '-':
                result = stack[top-2] - stack[top-1];
                stack[top-2] = result;
                top--;
                break;
            case '*':
                result = stack[top-2] * stack[top-1];
                stack[top-2] = result;
                top--;
                printf("hi *\n");
                break;
            case '/':
                result = stack[top-2] / stack[top-1];
                stack[top-2] = result;
                top--;
                break;
            default:
                stack[top++] = atoi(tokens[i]);
                break;
        }
    }
    return result;
}

int main (void)
{
    char arr[][4] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    printf("result = %d\n", evalRPN(arr,max));
    return 0;
}