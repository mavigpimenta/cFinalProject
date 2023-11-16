#ifndef GAME_APP_H
#define GAME_APP_H

    #include <stdio.h>
    #include <conio.h>
    #include <windows.h>
    #include "../scores/scores.h"

    void printHome(void);
    void printHighScores(void);
    void printGame(int * matrix, int size, int current_score);

#endif //GAME_APP_H