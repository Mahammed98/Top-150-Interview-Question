int maxProfit(int* prices, int pricesSize) 
{
    int i = 0;
    int MinNum = prices[0];
    int IndexMinNum = 0;
    int MaxProfit = 0;
    for(i = 1; i < pricesSize; i++)    
    {
        if(MinNum > prices[i])         // if other minimum number is found
        {
            MinNum = prices[i];
        }
        else         // calculate the maximum profit after the minimum number 
        {
            if(MaxProfit < (prices[i] - MinNum))
            {
                MaxProfit = prices[i] - MinNum;
            }
            else
            {
                //nothing
            }
        }
    }

    return MaxProfit;
}
