#include <stdio.h>
#include <stdlib.h>
#include "./events/events.h"
#include <windows.h>


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


int main(void)
{
    int size = 4;
    int * matrix = malloc(sizeof(int) * size * size);

    for(int i = 0; i < size*size; i++)
    {
        matrix[i] = 0;
    }

    generateNewNumber(matrix, size);
    generateNewNumber(matrix, size);

    for(;;) 
    {
        system("clear");
        char option;

        printMatrix(matrix, size);
        scanf(" %c", &option);

        switch (option)
        {
        case 'w':
            goUp(matrix, size);
            break;
        case 'd':
            goRight(matrix, size);
            break;
        case 'a':
            goLeft(matrix, size);
            break;
        case 's':
            goDown(matrix, size);
            break;

        default:
            printf("\nNot a valid choice\n");
            Sleep(1000);
            break;
        }
    }

    free(matrix);
    return 0;
}