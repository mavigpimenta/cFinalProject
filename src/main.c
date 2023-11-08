#include <stdio.h>
#include <stdlib.h>
#include "./events/events.h"
#include "./scores/scores.h"
#include <windows.h>


void printMatrix(int * matrix, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            switch (matrix[i * size + j])
            {
            case 0:
                printf("\033[0m%i\t", matrix[i * size + j]);
                break;
            case 2:
                printf("\033[31m%i\t", matrix[i * size + j]);
                break;
            case 4:
                printf("\033[32m%i\t", matrix[i * size + j]);
                break;
            case 8:
                printf("\033[33m%i\t", matrix[i * size + j]);
                break;
            case 16:
                printf("\033[34m%i\t", matrix[i * size + j]);
                break;
            case 32:
                printf("\033[35m%i\t", matrix[i * size + j]);
                break;
            default:
                printf("\033[36m%i\t", matrix[i * size + j]);
                break;
            }
        }
        printf("\n\n\n");
    }
    printf("\n");
}

void printScore(int current_score)
{
    printf("\n\n\033[0mScore: %i\n\n", current_score);
}


int main(void)
{
    srand(time(NULL));

    int current_score = 0;
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
        printScore(current_score);
        scanf(" %c", &option);

        switch (option)
        {
        case 'w':
            goUp(matrix, size, &current_score);
            break;
        case 'd':
            goRight(matrix, size, &current_score);
            break;
        case 'a':
            goLeft(matrix, size, &current_score);
            break;
        case 's':
            goDown(matrix, size, &current_score);
            break;
        case 'o':
            highscore(current_score);
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