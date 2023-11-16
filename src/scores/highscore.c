#include "./scores.h"


void saveScore(int player_score_int, char player_name[4])
{
    FILE * file_highscores;
    Score * old_scores = malloc(sizeof(Score) * 6);
    char crr_line[12], crr_name[4], crr_score[7], player_score[7] = "000000", str_for_print[10];
    Score old_score;
    int counter = 0;

    sprintf(player_score, "%06d", player_score_int);

    file_highscores = fopen("../scoreboard.txt", "r");

    while(fgets(crr_line, sizeof(crr_line), file_highscores) != NULL) {

        if(crr_line[0] == '\n')
            strncpy(crr_name, crr_line + 1, 3);
        else
            strncpy(crr_name, crr_line, 3);
        strncpy(crr_score, crr_line + 4, 6);
        crr_name[3] = '\0';
        crr_score[6] = '\0';

        strcpy(old_score.name, crr_name);
        strcpy(old_score.score, crr_score);
    
        old_scores[counter] = old_score;
        counter++;
    }

    fclose(file_highscores);
    file_highscores = fopen("../scoreboard.txt", "w");

    for(int i = 0; i < 6; i++)
    {
        strcpy(str_for_print, i == 5 ? "%s %s" : "%s %s\n");

        if(atoi(player_score) > atoi(old_scores[i].score))
        {
            fprintf(file_highscores, str_for_print, player_name, player_score);

            for(int j = i + 1; j < 6; j++)
            {
                strcpy(str_for_print, j == 5 ? "%s %s" : "%s %s\n");
                fprintf(file_highscores, str_for_print, old_scores[j].name, old_scores[j].score);
            }
            break;
        }
        else
            fprintf(file_highscores, str_for_print, old_scores[i].name, old_scores[i].score);
    }
    fclose(file_highscores);
    free(old_scores);
}