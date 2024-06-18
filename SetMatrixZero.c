#include <stdio.h>
#include <stdlib.h>
typedef struct index
{
    unsigned char row;
    unsigned char col;
} INDEX;

void setZeroes(int[3][4] , int , int* ) ;

int main(void)
{
    int m = 3;
    int n = 4;
    int arr[][4] = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(arr,m,&n);
    for(int i = 0; i < m; i++)  
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
void setZeroes(int matrix[3][4], int matrixSize, int* matrixColSize) 
{
    INDEX arr[40000] = {-1,-1};
    int x = 0;
    printf("size of colums = %ld\n", (sizeof(matrix[0])/sizeof(matrix[0][0])));
    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < (sizeof(matrix[0])/sizeof(matrix[0][0])); j++)
        {
            if(matrix[i][j] == 0)
            {
                arr[x].row = i;
                arr[x].col = j;
                x++;
            }
        }
    }
    printf("x = %d\n", x);
    for(int i = 0; i < x; i++)
    {
        
            for(int y = 0; y < (sizeof(matrix[0])/sizeof(matrix[0][0])); y++)
            {
                matrix[arr[i].row][y] = 0;
            }
            for(int z = 0; z < matrixSize; z++)
            {
                matrix[z][arr[i].col] = 0;
            }
        
    }
}