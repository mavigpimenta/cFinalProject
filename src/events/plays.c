#include "./events.h"


void goRight(int * matrix, int size, int * current_score)
{
    int received_array[size*size];

    for(int i = 0; i < size; i++)
    {
        for(int j = size - 1; j > -1; j--)
        {
            received_array[i * size + j] = matrix[i * size + j];

            for(int k = j - 1; k > - 1; k--)
            {
                if(matrix[i * size + k] != 0)
                {
                    if(matrix[i * size + k] != matrix[i * size + j])
                        break;
                    else
                    {
                        matrix[i * size + j] = matrix[i * size + k] + matrix[i * size + j];
                        matrix[i * size + k] = 0;
                        *current_score += matrix[i * size + j];
                        break;
                    }
                }
            }
        }

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

    for(int i = 0; i < size*size; i++)
    {
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
                        *current_score += matrix[i * size + j];
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
                        *current_score += matrix[j * size + i];
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
                        *current_score += matrix[j * size + i];
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
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(matrix[i * size + j] == 0)
                return 1;

            else if(matrix[i * size + j] == matrix[i * size + j + 1])
            {
                return 1;
            }
            else if(matrix[i * size + j] == matrix[i * size + j - 1])
            {
                return 1;
            }
            else if(matrix[i * size + j] == matrix[(i - 1) * size + j])
            {
                return 1;
            }
            else if(matrix[i * size + j] == matrix[(i + 1) * size + j])
            {
                return 1;
            }
        }
    }
    return 0;
}