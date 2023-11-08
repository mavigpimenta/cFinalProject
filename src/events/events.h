#ifndef GAME_EVENTS_H
#define GAME_EVENTS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void goRight(int * matrix, int size);
    void goLeft(int * matrix, int size);
    void goUp(int * matrix, int size);
    void goDown(int * matrix, int size);

    void generateNewNumber(int * matrix, int size);

#endif //GAME_EVENTS_H