/*
    You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.

    Example 1:

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

    Example 2:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false
    

    Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104

*/
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int key) 
{
    int low = 0, high = *matrixColSize-1;
    int up = 0, down = matrixSize-1;
    int mid, j;
    int flag = 0;
    int MidInCol, MidInRow;
    /*
        first search in each Rows in first coloum 
    */
    while(up <= down)
    {
        MidInCol = (up + down) / 2;

        if(key == matrix[MidInCol][0])
        {
            flag = 1;
            break;
        }
        else if (key < matrix[MidInCol][0])
        {
            down = MidInCol -1;
        }
        else
        {
            up = MidInCol + 1;
        }
    }
    /*
        if key not found in first coloum, so search on row which mid pointer is was stopped 
        key may be in this row or previous row
    */
    if(!flag)
    {
        if (key < matrix[MidInCol][0] && MidInCol != 0)
        {
            MidInCol--;
        }
        while(low <= high)
        {
            MidInRow = (low + high) / 2;

            if(key == matrix[MidInCol][MidInRow])
            {
                flag = 1;
                break;
            }
            else if (key < matrix[MidInCol][MidInRow])
            {
                high = MidInRow -1;
            }
            else
            {
                low = MidInRow + 1;
            }
        }
    }
    else
    {

    }

    return flag;
    
}