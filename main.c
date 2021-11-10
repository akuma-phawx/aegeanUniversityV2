#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int rows, columns;

// Returns true if s is a number else false
int isNumber(char s[])
{
    for (int i = 0; i < sizeof(s); i++)
        if (isdigit(s[i]) == 1)
            return -1;

    return 1;
}

void runExerciseOne()
{
}

void calculateNewTable(int initialTable[rows][columns], int newTable[rows][columns])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == j)
            {
                int rowMax = initialTable[i][0];
                for (int tempj = 0; tempj < columns; tempj++)
                {
                    if (initialTable[i][tempj] > rowMax)
                    {
                        rowMax = initialTable[i][tempj];
                    }
                }
                newTable[i][j] = rowMax;
            }
            else if (i % 2 != 0 && j % 2 == 0)
            {
                int columnMax = initialTable[0][j];
                for (int tempi = 0; tempi < rows; tempi++)
                {
                    if (initialTable[tempi][j] > columnMax)
                    {
                        columnMax = initialTable[tempi][j];
                    }
                }
                newTable[i][j] = columnMax;
            }
            else if (i % 2 == 0 && j % 2 != 0)
            {
                int rowMin = initialTable[i][0];
                for (int tempj = 0; tempj < columns; tempj++)
                {
                    if (initialTable[i][tempj] < rowMin)
                    {
                        rowMin = initialTable[i][tempj];
                    }
                }
                newTable[i][j] = rowMin;
            }
            else
            {
                newTable[i][j] = 0;
            }
        }
    }

    printf("\nOur new 2 Dimensional Array is calculated. Array content:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("| %d |", newTable[i][j]);
            if (j == columns - 1)
            {
                printf("\n");
            }
        }
    }
}

void runExerciseTwo()
{
    printf("not implemented");
}
void runExerciseThree()
{
    printf('not implemented');
}

void runExerciseFour()
{
    int flag;
    flag = 0;

    do
    {
        if (flag == 1)
        {
            printf("INVALID INPUT TRY AGAIN\n\n");
        }
        printf("Please enter Number of rows (min 0 max 6): ");
        scanf("%d", &rows);
        printf("\tNumber of rows given: %d\n\n", rows);
        printf("Please enter Number of columns (min 0 max 6): ");
        scanf("%d", &columns);
        printf("\tNumber of rows given: %d\n\n", columns);
        flag = 1;
    } while (rows < 0 || rows > 6 || columns < 0 || columns > 6);

    fflush(stdin);
    int initialTable[rows][columns];
    int newTable[rows][columns];

    printf("\n\nTable Created A[%d][%d]\n\n", rows, columns);
    printf("Please fill the table: \n\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("\tA[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &initialTable[i][j]);
        }
    }

    fflush(stdin);
    printf("\nOur 2 Dimensional Array is filled. Array content:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("| %d |", initialTable[i][j]);
            if (j == columns - 1)
            {
                printf("\n");
            }
        }
    }

    printf("\nCalculating new table..\n\n");
    calculateNewTable(initialTable, newTable);
}

int main(int argc, char **argv)
{

    char input[10];

    do
    {
        printMenu();
        printf("Enter: ");
        scanf("%s", &input);
        printf("\n------------------------------------\n");
        int inputToInteger = atoi(input);
        switch (inputToInteger)
        {
        case 1:
            printf("|      Running Exercise 1          |\n");
            printf("------------------------------------\n\n");
            runExerciseOne();
            break;
        case 2:
            printf("|      Running Exercise 2          |\n");
            printf("------------------------------------\n\n");
            runExerciseTwo();
            break;
        case 3:
            printf("|      Running Exercise 3          |\n");
            printf("------------------------------------\n\n");
            runExerciseThree();
            break;
        case 4:
            printf("|      Running Exercise 4          |\n");
            printf("------------------------------------\n\n");
            runExerciseFour();
            break;
        case 5:
            printf("|       Now exiting..Byebye!       |\n");
            printf("------------------------------------\n\n");
            exit(0);
            break;
        default:
            printf("| Invalid Input, please try again. |\n");
            printf("------------------------------------\n\n");
            break;
        }
    } while (isNumber(input) == -1 || input < 1 || input > 4);
    return 0;
}

void printMenu()
{

    printf("[Menu]:\n");
    printf("\t[1]Run exercise 1 (Maclaurin Series)\n");
    printf("\t[2]Run exercise 2 (Recursive Function)\n");
    printf("\t[3]Run exercise 3 (Character Print)\n");
    printf("\t[4]Run exercise 4 (2 Dimension Exercise)\n");
    printf("\t[5]Exit\n\n");
}
