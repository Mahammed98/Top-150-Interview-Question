double myPow(double x, int n) 
{
    long long Num;  // power
    double result = 1.0; 
    if(n < 0)       // if power was negative 
    {
        Num = -1 * (long long)n;
    }
    else
    {
        Num = n;
    }
   
    while(Num)
    {   
        if(Num%2)
        {
            result *= x;
            Num--;
        }
        else
        {
            x = x * x;
            Num /= 2;
        }    
    } // end while loop

    if(n < 0) // if power was negative, so we divided it by one 
    {
        result = 1.0/result;
    }
    return result;
}