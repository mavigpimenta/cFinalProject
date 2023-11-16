#include "./app.h"


void printHome(void)
{
    MOVE_HOME();
    ERASE_ALL();

    char start;

    printf("#####################################################################\n");
    printf("#                                                                   #\n");
    printf("#                                                                   #\n");
    printf("#                                                                   #\n");
    printf("#                 ####   ####   #####   ###    ###                  #\n");
    printf("#                 #   #  #   #  #      #      #                     #\n");
    printf("#                 ####   ####   #####   ###    ###                  #\n");
    printf("#                 #      #  #   #          #      #                 #\n");
    printf("#                 #      #   #  #####   ###    ###                  #\n");
    printf("#                                                                   #\n");
    printf("#                                                                   #\n");
    printf("#                 #####  #   #  #####  #####  ####                  #\n");
    printf("#                 #      ##  #    #    #      #   #                 #\n");
    printf("#                 #####  # # #    #    #####  ####                  #\n");
    printf("#                 #      #  ##    #    #      #  #                  #\n");
    printf("#                 #####  #   #    #    #####  #   #                 #\n");
    printf("#                                                                   #\n");
    printf("#                                                                   #\n");
    printf("#                   Press H to see highscores...                    #\n");
    printf("#                                                                   #\n");
    printf("#                                                                   #\n");
    printf("#                                                                   #\n");
    printf("#####################################################################\n");

    fflush(stdout);

    while ((start = getch()))
        if(start == 13) break;
        else if(start == 'h' || start == 'H')
        {
            printHighScores();
            while((start = getch()))
                if(start == 27)
                    break;
            printHome();
        }
}


void printGame(int * matrix, int size, int current_score)
{
    printf("\033[36m\tSCORE: %i\n\n\n", current_score);

    for(int i = 0; i < size; i++)
    {
        printf("\t");
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
        printf("\033[0m\n\n\n");
    }
    printf("\n");
}

void printHighScores(void)
{
    MOVE_HOME();
    ERASE_ALL();

    char line[12];
    FILE * file_highscores;
    file_highscores = fopen("../scoreboard.txt", "r");

    printf("#####################################################################\n");
    printf("#                                                                   #\n");
    printf("#                                                                   #\n");
    while(fgets(line, sizeof(line), file_highscores) != NULL)
    {
        line[12] = '\0';
        line[10] = ' ';
        printf("#                           %s                             #\n", line);
        printf("#                                                                   #\n");
    }
    printf("#                                                                   #\n");
    printf("#                                                                   #\n");
    printf("#                                                                   #\n");
    printf("#                                                                   #\n");
    printf("#                      Press Esc to go back...                      #\n");
    printf("#                                                                   #\n");
    printf("#                                                                   #\n");
    printf("#####################################################################\n");
    fflush(stdout);
    fclose(file_highscores);
}