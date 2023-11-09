#ifndef GAME_GAME_RUNGAME_H
#define GAME_GAME_RUNGAME_H

    #include <stdio.h>
    #include <windows.h>
    #include "../events/events.h"
    #include "../scores/scores.h"

    void runGameLoop(int * matrix, int size, int current_score);
    void printMatrix(int * matrix, int size);
    void printScore(int current_score);

#endif //GAME_GAME_RUNGAME_H