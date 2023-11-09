#include "./scores.h"
#include <math.h>

void printScoreFile(int * current_score)
{
    FILE * file_highscores;
    file_highscores = fopen("scoreboard.txt", "r");
    Score * highscores = malloc(sizeof(Score) * 6);
    int line = 0;

    while ((c = fgetc(file_highscores)) != EOF) 
    {
        char aux[11];
        aux[10] = '\0';
        int i = 0;
        int score = 0;

        while ((c = fgetc(file_highscores)) != '\n')
        {
            aux[i] = c;
            i++;
        }

        for (int j = 4; j < 10; j++)
        {
            score += aux[j] * pow(10, 9 - j)
        }
        if (current_score > score)
        {
            
            score = current_score;

        }
        line++;
    }
}

void getHighscores(int * current_score)
{

}