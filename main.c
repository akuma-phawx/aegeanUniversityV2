#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void runExerciseOne()
{
    printf("not implemented");
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
    printf('not implemented');
}

// Returns true if s is a number else false
int isNumber(char s[])
{
    for (int i = 0; i < sizeof(s); i++)
        if (isdigit(s[i]) == 1)
            return -1;

    return 1;
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
    printf("\t[3]Run exercise 4 (Tables Exercise)\n");
    printf("\t[5]Exit\n\n");
}
