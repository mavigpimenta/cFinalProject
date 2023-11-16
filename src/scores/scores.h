#ifndef GAME_SCORES_H
#define GAME_SCORES_H

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "../app/terminal.h"
    
    typedef struct
    {
        char name[4];
        char score[7];
    } Score;

    void saveScore(int player_score_int, char player_name[4]);


#endif //GAME_SCORES_H