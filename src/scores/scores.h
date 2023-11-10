#ifndef GAME_SCORES_H
#define GAME_SCORES_H

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    
    typedef struct
    {
        char name[4];
        char score[7];
    } Score;

    void saveScore(int player_score, char player_name);


#endif //GAME_SCORES_H