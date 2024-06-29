/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) 
{
    int counter = 0;
    int start = 0;
    int end = 0;
    int iteration = 0;
    int i = 0;
    bool flag = 0;
    int size = matrixSize*(*matrixColSize);
    int *result  = (int*)malloc(sizeof(int)*100);
    while(counter < size)
    {
        /*  
            store print upper row
        */
        for(i = start; i < *matrixColSize-end; i++) 
        {
            result[iteration++] = matrix[start][i];
            counter++; // 1 2 3 4 11 12
            if(counter == size) 
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            break;
        }
        /*
            store right colum
        */
        for(i = start+1; i < matrixSize-end; i++)
        {
            result[iteration++] = matrix[i][*matrixColSize-end-1];
            counter++; // 5 6 
            if(counter == size) 
            {
                flag = 1;
                break;
            }

        }
        if(flag)
        {
            break;
        }
        /*
            store lower row
        */
        for(i = *matrixColSize-end-2; i >= start; i--)
        {
            result[iteration++] = matrix[matrixSize-end-1][i];
            counter++; // 7 8 9
            if(counter == size) 
            {
                flag = 1;
                break;
            }

        }
        if(flag)
        {
            break;
        }
        /*
            store left col
        */
        for(i = matrixSize-end-2; i > start; i--)
        {
            result[iteration++] = matrix[i][start];
            counter++; // 10

        }
        /*
            increase the pointer of end and start(go to new inner matrix)
        */
        start++; // 1
        end++; // 1
    }
    *returnSize = counter;
    return result;
}