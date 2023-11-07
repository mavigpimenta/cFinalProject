
#include "./plays.h"


void goRight(int * matrix, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = size - 1; j > -1; j--)
        {
            if(matrix[i * size + j] == 0)
            {
                for(int k = j; k > 0 ; k--)
                {
                    matrix[i * size + k] = matrix[i * size + k - 1];
                    matrix[i * size + k - 1] = 0;
                }
                
            }
            else
            {
                for(int k = j - 1; k > - 1; k--)
                {
                    if(matrix[i * size + k] != 0 && matrix[i * size + k] != matrix[i * size + j]) break;
                     
                    else if(matrix[i * size + k] == matrix[i * size + j])
                    {
                        matrix[i * size + j] = matrix[i * size + k] + matrix[i * size + j];
                        matrix[i * size + k] = 0;
                        break;
                    }
                }
            }
        }
    }
}


void goLeft(int * matrix, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(matrix[i * size + j] == 0)
            {
                for(int k = j; k < size ; k++)
                {
                    matrix[i * size + k] = matrix[i * size + k + 1];
                    matrix[i * size + k + 1] = 0;
                }
                
            }
            else
            {
                for(int k = j; k < size ; k++)
                {
                    if(matrix[i * size + k] != 0 && matrix[i * size + k] != matrix[i * size + j])
                        break;
                     
                    else if(matrix[i * size + k] == matrix[i * size + j])
                    {
                        matrix[i * size + j] = matrix[i * size + k] + matrix[i * size + j];
                        matrix[i * size + k] = 0;
                        break;
                    }
                }
            }
        }
    }
}