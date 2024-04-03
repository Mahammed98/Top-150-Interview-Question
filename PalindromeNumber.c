/*
    Given an integer x, return true if x is a 
    palindrome
    , and false otherwise.

    

    Example 1:
    Input: x = 121
    Output: true
    Explanation: 121 reads as 121 from left to right and from right to left.

    Example 2:
    Input: x = -121
    Output: false
    Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

    Example 3:
    Input: x = 10
    Output: false
    Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
    

    Constraints:
    -231 <= x <= 231 - 1



*/
bool isPalindrome(int x) 
{
    if (x<0){
            return false;
        }
        int temp=x;
        long long int reversed_num = 0;
        int digit;
        while(temp != 0){
            digit = temp % 10;
            reversed_num = reversed_num * 10 + digit;
            temp /= 10;
        }
        return reversed_num==x;
}


// onther solution 

/*
    bool isPalindrome(int x) 
    {
        int NumberOfDigits = 0;
        int *arr = (int*)calloc(1,sizeof(int));
        int temp = x;
        bool result = 1;
        if(x < 0)
        {
            result = 0;
        }
        else
        {
            while(temp != 0)
            {
                arr[NumberOfDigits] = temp%10;
                temp /= 10;
                NumberOfDigits++;
                arr = (int*) realloc(arr, (NumberOfDigits+1)*sizeof(int));
            }
            for(int i = 0; i < (NumberOfDigits/2); i++)
            {
                if(arr[i] != arr[NumberOfDigits-i-1])
                {
                    result = false;
                    break;
                }
            }
        }

        free(arr);
        return result ;
    }


*/