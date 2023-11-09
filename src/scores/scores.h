#ifndef GAME_SCORES_H
#define GAME_SCORES_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>
    
    typedef struct
    {
        char name[3];
        int score;
    } Score;

    void getHighscores(int * current_score);
    void printScoreFile(int * current_score);

#endif //GAME_SCORES_H