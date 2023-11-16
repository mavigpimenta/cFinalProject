#include "./events.h"


void goRight(int * matrix, int size, int * current_score)
{
    // a variable to save the old array
    int received_array[size*size];

    // iterate through the lines
    for(int i = 0; i < size; i++)
    {
        // iterate through the columns
        for(int j = size - 1; j > -1; j--)
        {
            // save the old matrix, number by number
            received_array[i * size + j] = matrix[i * size + j];

            // go to the next number that's not a zero
            for(int k = j - 1; k > - 1; k--)
            {
                if(matrix[i * size + k] != 0)
                {
                    // if it's different, just skip
                    if(matrix[i * size + k] != matrix[i * size + j])
                        break;
                    else
                    {
                        // if they're equal, join them
                        matrix[i * size + j] = matrix[i * size + k] + matrix[i * size + j];
                        matrix[i * size + k] = 0;
                        // add the value of the new number to the score
                        (*current_score) += matrix[i * size + j];
                        break;
                    }
                }
            }
        }

        // now move everyone to the chosen direction
        for(int j = size - 1; j > -1; j--)
        {
            for(int k = size - 1; k > - 1; k--)
            {
                if(matrix[i * size + j] == 0)
                {
                    for(int l = j; l > 0 ; l--)
                    {
                        matrix[i * size + l] = matrix[i * size + l - 1];
                        matrix[i * size + l - 1] = 0;
                    }
                }
            }
        }
    }

    // iterate through the old and the new matrix, comparing numbers
    for(int i = 0; i < size*size; i++)
    {
        // if any number changed, generate a new number in a random spot
        if(matrix[i] != received_array[i])
        {
            generateNewNumber(matrix, size);
            break;
        }
    }
}


void goLeft(int * matrix, int size, int * current_score)
{
    int received_array[size*size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            received_array[i * size + j] = matrix[i * size + j];

            for(int k = j + 1; k < size ; k++)
            {
                if(matrix[i * size + k] != 0)
                {
                    if(matrix[i * size + k] != matrix[i * size + j])
                        break;
                    else
                    {
                        matrix[i * size + j] = matrix[i * size + k] + matrix[i * size + j];
                        matrix[i * size + k] = 0;
                        (*current_score) += matrix[i * size + j];
                        break;
                    }
                }
            }
        }

        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                if(matrix[i * size + j] == 0)
                {
                    for(int l = j; l < size - 1 ; l++)
                    {
                        matrix[i * size + l] = matrix[i * size + l + 1];
                        matrix[i * size + l + 1] = 0;
                    }
                }
            }
        }
    }

    for(int i = 0; i < size*size; i++)
    {
        if(matrix[i] != received_array[i])
        {
            generateNewNumber(matrix, size);
            break;
        }
    }
}


void goUp(int * matrix, int size, int * current_score)
{
    int received_array[size*size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            received_array[i * size + j] = matrix[i * size + j];

            for(int k = j + 1; k < size ; k++)
            {
                if(matrix[k * size + i] != 0)
                {
                    if(matrix[j * size + i] != matrix[k * size + i])
                        break;
                    else
                    {
                        matrix[j * size + i] = matrix[j * size + i] + matrix[k * size + i];
                        matrix[k * size + i] = 0;
                        (*current_score) += matrix[j * size + i];
                        break;
                    }
                }
            }
        }

        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                if(matrix[j * size + i] == 0)
                {
                    for(int l = j; l < size - 1 ; l++)
                    {
                        matrix[l * size + i] = matrix[(l + 1) * size + i];
                        matrix[(l + 1) * size + i] = 0;
                    }
                }
            }
        }
    }

    for(int i = 0; i < size*size; i++)
    {
        if(matrix[i] != received_array[i])
        {
            generateNewNumber(matrix, size);
            break;
        }
    }
}


void goDown(int * matrix, int size, int * current_score)
{
    int received_array[size*size];

    for(int i = 0; i < size; i++)
    {
        for(int j = size - 1; j > -1; j--)
        {
            received_array[i * size + j] = matrix[i * size + j];

            for(int k = j - 1; k > - 1; k--)
            {
                if(matrix[k * size + i] != 0)
                {
                    if(matrix[j * size + i] != matrix[k * size + i])
                        break;
                    else
                    {
                        matrix[j * size + i] = matrix[j * size + i] + matrix[k * size + i];
                        matrix[k * size + i] = 0;
                        (*current_score) += matrix[j * size + i];
                        break;
                    }
                }
            }
        }

        for(int j = size - 1; j > -1; j--)
        {
            for(int k = size - 1; k > - 1; k--)
            {
                if(matrix[j * size + i] == 0)
                {
                    for(int l = j; l > 0; l--)
                    {
                        matrix[l * size + i] = matrix[(l - 1) * size + i];
                        matrix[(l - 1) * size + i] = 0;
                    }
                }
            }
        }
    }

    for(int i = 0; i < size*size; i++)
    {
        if(matrix[i] != received_array[i])
        {
            generateNewNumber(matrix, size);
            break;
        }
    }
}


void generateNewNumber(int * matrix, int size)
{
    int random_number, new_block, max_number;
    max_number = size*size;
    
    random_number = rand() % max_number;
    new_block = random_number <= size ? 4 : 2;

    for(int i = random_number; i <= max_number; i++)
    {
        if(i == max_number)
        {
            i = 0;
        }
        if(matrix[i] == 0)
        {
            matrix[i] = new_block;
            break;
        }
    }
}

int verifyMatrix(int * matrix, int size)
{
    // iterate through the matrix
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            // check if there are no zeros, then check if any number has a possible play
            if(matrix[i * size + j] == 0)
                return 1;
            else if(j < size - 1 && matrix[i * size + j] == matrix[i * size + j + 1])
                return 1;
            else if(j > 0 && matrix[i * size + j] == matrix[i * size + j - 1])
                return 1;
            else if(i > 0 && matrix[i * size + j] == matrix[(i - 1) * size + j])
                return 1;
            else if(i < size - 1 && matrix[i * size + j] == matrix[(i + 1) * size + j])
                return 1;
    // if there are no plays, return 0 and stop the game
    return 0;
}