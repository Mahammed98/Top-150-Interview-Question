

int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int *result = (int*)calloc(digitsSize, sizeof(int));
    int curry = 0;
    digits[digitsSize-1]++;  
    for(int i = digitsSize-1; i >= 0; i--)
    {
        digits[i] += curry;
        if(digits[i]== 10)
        {
            curry = 1;
            result[i] = 0;
        }
        else
        {
            curry = 0;
            result[i] = digits[i];
        }
    }
    if(curry)       // if we have a curry so we gonna increase the size of array 
    {
        /*
            this condition accure when all elements of array digits are 9's
            ex : 9, 99, 999, 9999,....
            so first element on result array must be 1 and last(new element added)must be zero
        */ 
        result = realloc(result, (sizeof(int) * (digitsSize+1)));
        result[0] = 1;
        result[digitsSize] = 0;
    }
    else
    {
        // no action
    }
    *returnSize = digitsSize+curry;
    return result;
}