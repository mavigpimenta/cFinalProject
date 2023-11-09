#include "./rungame.h"


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


void runGameLoop(int * matrix, int size, int current_score)
{
    int run = 1;
    
    while(run == 1) 
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
            run = 0;
            break;
        default:
            printf("\nNot a valid choice\n");
            Sleep(1000);
            break;
        }

        run = verifyMatrix(matrix, size);
    }
}