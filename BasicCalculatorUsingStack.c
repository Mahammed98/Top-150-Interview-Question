int calculate(char* s) 
{
    int stack[75000];
    int top = -1;
    int Number = 0;        // container of the number
    int result = 0;           
    int sign = 1;
    int i = 0; 
    while(s[i] != '\0')
    {
        if(s[i] >= '0'&& s[i] <= '9')
        {
            Number = Number * 10 +  (s[i] - '0');    // convert each digit of number to integer and add it in to Number
        }
        else if(s[i] == '+')
        {
            result += sign * Number;
            /*  reset number */
            Number = 0;
            sign = 1;     // set sign as + (1)

        }
        else if(s[i] == '-')
        {
            result += sign * Number;
            /*  reset number  */
            Number = 0;
            sign = -1;  // set sign as - (-1)
        }
        else if(s[i] == '(')
        {
            /*
                store previous sign and result befour braket
            */
            stack[++top] = result;    
            stack[++top] = sign;
            /*  reset valus */
            result = 0;
            sign = 1;
        }
        else if(s[i] == ')')
        {
            result += sign * Number;
            Number = 0;
            result *= stack[top--];   // add previous sign  befour braket
            result += stack[top--];   // add previous value befour braket
        }
        i++;
    }
    result += sign * Number;
    return result;
}