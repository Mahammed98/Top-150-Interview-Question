int rangeBitwiseAnd(int left, int right) {
    unsigned int result = 0;
    
    for(int j = 31; j >= 0; j--) { // Start from the most significant bit
        unsigned int mask = 1u << j; // Create a mask for the j-th bit
        
        // Check if the j-th bit is set in both left and right
        if ((left & mask) == (right & mask)) {
            result |= (left & mask); // Set the j-th bit in the result if it's the same in both left and right
        } else {
            break; // Break the loop if the bits are different
        }
    }
    
    return result;
}
/*
    // this code take much time to execut
int rangeBitwiseAnd(int left, int right) 
{
    unsigned int result1 = 0;
    unsigned int result2 = 0;
    for(int j = 31; j >= 0; j--)
    {
        for(unsigned int i = left; i <= right; i++)
        {
           result1 = ((1u<<j)&i);
           if(result1 == 0)
           {
                break;
           }
        }
        result2 |= result1;
    }
    
    return result2;
}
*/