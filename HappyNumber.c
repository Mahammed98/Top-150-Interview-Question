int Calculate(int number)
{
    int sum = 0;
    while(number)
    {
        sum += ((number%10) * (number%10));
        number /= 10;
    }
    return sum;
}
bool isHappy(int n) 
{
    int hash[731] = {0};
    bool result = 0;
    while(1)
    {
        n = Calculate(n);
        hash[n] += 1;
        if(n == 1)
        {
            result = 1;
            break;
        }
        else if(hash[n] > 1)
        {
            break;
        }
    }
    //free(hash);
    return result;
}