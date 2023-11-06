
#include "./plays.h"


void goRight(int * matrix, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = size; j > -1; j--)
        {
            for(int k = j - 1; k > - 1; k--)
            {
                if(matrix[i * size + k] != 0 && matrix[i * size + k] != matrix[i * size + j])
                {
                    matrix[i * size + j - 1] = matrix[i * size + k];
                    matrix[i * size + k] = 0;
                    break;
                } else if(matrix[i * size + k] == matrix[i * size + j])
                {
                    matrix[i * size + j] = matrix[i * size + k] + matrix[i * size + j];
                    matrix[i * size + k] = 0;
                    break;
                }
            }
        }
    }
}