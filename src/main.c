#include <stdio.h>
#include <stdlib.h>
#include "./events/plays.h"


void printMatrix(int * matrix, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%i ", matrix[i * size + j]);
        }
        printf("\n");
    }
    printf("\n");
}


// void goRight(int * matrix, int size)
// {
//     for(int i = 0; i < size; i++)
//     {
//         for(int j = size - 1; j > -1; j--)
//         {
//             if(matrix[i * size + j] == 0)
//             {
//                 for(int k = j; k > 0 ; k--)
//                 {
//                     matrix[i * size + k] = matrix[i * size + k - 1];
//                     matrix[i * size + k - 1] = 0;
//                 }
                
//             }
//             else
//             {
//                 for(int k = j - 1; k > - 1; k--)
//                 {
//                     if(matrix[i * size + k] != 0 && matrix[i * size + k] != matrix[i * size + j]) break;
                     
//                     else if(matrix[i * size + k] == matrix[i * size + j])
//                     {
//                         matrix[i * size + j] = matrix[i * size + k] + matrix[i * size + j];
//                         matrix[i * size + k] = 0;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
// }


int main(void)
{
    int size = 4;
    int * matrix = malloc(sizeof(int) * size * size);

    for(int i = 0; i < size*size; i++)
    {
        matrix[i] = 0;
    }


    matrix[0 * size + 2] = 2;
    matrix[0 * size + 3] = 2;
    matrix[0 * size + 1] = 4;
    matrix[0 * size + 0] = 2;

    matrix[1 * size + 2] = 8;
    matrix[1 * size + 3] = 4;
    matrix[1 * size + 1] = 256;
    matrix[1 * size + 0] = 256;

    matrix[2 * size + 2] = 8;
    matrix[2 * size + 3] = 16;
    matrix[2 * size + 1] = 8;
    matrix[2 * size + 0] = 8;

    matrix[3 * size + 2] = 32;
    matrix[3 * size + 3] = 16;
    matrix[3 * size + 1] = 16;
    matrix[3 * size + 0] = 64;

    printMatrix(matrix, size);
    goRight(matrix, size);
    printMatrix(matrix, size);
    goRight(matrix, size);
    printMatrix(matrix, size);
    
    return 0;
}