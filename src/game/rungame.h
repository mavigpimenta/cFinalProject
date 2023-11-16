#ifndef GAME_GAME_RUNGAME_H
#define GAME_GAME_RUNGAME_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <conio.h>
    #include <windows.h>
    #include "../events/events.h"
    #include "../scores/scores.h"
    #include "../app/app.h"
    #include "../app/terminal.h"

    void runGameLoop(int * matrix, int size, int * current_score);


#endif //GAME_GAME_RUNGAME_H