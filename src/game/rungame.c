#include "./rungame.h"


void runGameLoop(int * matrix, int size, int * current_score)
{
    int run = 1;
    char option, confirm;

    
    while(run == 1) 
    {

        MOVE_HOME();
        ERASE_ALL();
        printGame(matrix, size, *current_score);
        fflush(stdout);
        option = getch();

        switch (option)
        {
        case 'w':
        case 'W':
        case 72:
            goUp(matrix, size, current_score);
            break;

        case 'd':
        case 'D':
        case 77:
            goRight(matrix, size, current_score);
            break;

        case 'a':
        case 'A':
        case 75:
            goLeft(matrix, size, current_score);
            break;
            
        case 's':
        case 'S':
        case 80:
            goDown(matrix, size, current_score);
            break;

        case 'o':
        case 'O':
            printf("\nAre you sure you wish to leave?\n\033[31mYour score won't be saved.\033[0m (y/n) ");
            fflush(stdout);
            scanf(" %c", &confirm);

            if(confirm == 'y' || confirm == 'Y')
            {
                run = 0;
                Sleep(2000);
            }
            break;
        }

        if(option != 'o')
            run = verifyMatrix(matrix, size);
    }
    
    MOVE_HOME();
    ERASE_ALL();
    printGame(matrix, size, *current_score);
    printf("\n\033[31mGAME OVER\033[0m\n");
    fflush(stdout);
}