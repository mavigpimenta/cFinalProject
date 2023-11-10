#include "./scores.h"


void saveScore(int player_score, char player_name)
{
    FILE * file_highscores;
    Score * old_scores = malloc(sizeof(Score) * 6);
    char crr_line[12], crr_name[4], crr_score[7];
    Score old_score;
    int counter = 0;

    file_highscores = fopen("src/scores/scoreboard.txt", "r");

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

    for(int i = 0; i < 6; i++)
        printf("\nname: %s | score: %s", old_scores[i].name, old_scores[i].score);

    fclose(file_highscores);
}