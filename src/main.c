#include <stdio.h>
#include <stdlib.h>
#include "./events/events.h"
#include "./scores/scores.h"
#include "./game/rungame.h"


int main(void)
{
    srand(time(NULL));

    int current_score = 0, size = 4;
    int * matrix = malloc(sizeof(int) * size * size);

    for(int i = 0; i < size*size; i++)
    {
        matrix[i] = 0;
    }

    generateNewNumber(matrix, size);
    generateNewNumber(matrix, size);

    runGameLoop(matrix, size, current_score);

    free(matrix);
    return 0;
}