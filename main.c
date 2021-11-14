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
long getFactorial(int x){
    long result = 1;

    for (int i = 1; i <= x; i++){
        result = result * i;
    }

    return result;
}

void calculateMaclaurin(double x,int N){
    double functionResult = 0.0;
    for(int i = 0; i <= N; i++){
        double numerator = pow(-1,i);
        long denominator = getFactorial((2*i +1));
        functionResult+= (numerator/denominator) * pow(x, (2*i+1));
    }

      printf("\n\n\tFor x=%.2lf, f(x)=%.2lf\n\n\n",x,functionResult);
}

void runExerciseOne()
{
    double number;
    int terms;
    printf("Please enter a number (x): ");
    scanf("%lf", &number);
    fflush(stdin);
    printf("Please enter number of Terms (N): ");
    scanf("%d", &terms);
    fflush(stdin);

    calculateMaclaurin(number,terms);
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

    printf("\n\tOur new 2 Dimensional Array has been created. Array content:\n");
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
    printf("\n\n--------------------------\n\n");
}

void runExerciseTwo()
{
    printf("not implemented\n\n");
}
void runExerciseThree()
{
    printf("not implemented\n\n");
}

void runExerciseFour()
{
    int flag;
    flag = 0;
    char input[10];
    do
    {
        printf("Please enter Number of ROWS (min 0 max 6) or press 9 to cancel: ");
        scanf("%s", &input);
        printf("\n------------------------------------\n");
        rows = atoi(input);
        switch(rows)
        {
        case 1 ... 6:
            flag = 1;
            break;
        case 9:
            printf("|       Returning to Main Menu..   |\n");
            printf("------------------------------------\n\n");
            return;
            break;
        default:
            printf("| Invalid Input, please try again. |\n");
            printf("------------------------------------\n\n");
            break;
        }

        if(flag==1) break;
    }
    while (isNumber(input) == -1 || input < 0 || input > 6);

    fflush(stdin);
    flag=0;

    do
    {
        printf("Please enter Number of COLUMNS (min 0 max 6) or press 9 to cancel: ");
        scanf("%s", &input);
        printf("\n------------------------------------\n");
        columns = atoi(input);
        switch(columns)
        {
        case 1 ... 6:
            flag = 1;
            break;
        case 9:
            printf("|       Returning to Main Menu..   |\n");
            printf("------------------------------------\n\n");
            return;
            break;
        default:
            printf("| Invalid Input, please try again. |\n");
            printf("------------------------------------\n\n");
            break;
        }

        if(flag==1) break;
    }
    while (isNumber(input) == -1 || input < 0 || input > 6);


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
    printf("\n\tOur 2 Dimensional Array is filled. Array content:\n");
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

    printf("\nCreating new table..\n\n");
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
    }
    while (isNumber(input) == -1 || input < 1 || input > 4);
    return 0;
}

void printMenu()
{

    printf("[Menu]:\n");
    printf("\t[1] Run exercise 1 (Maclaurin Series)\n");
    printf("\t[2] Run exercise 2 (Recursive Function)\n");
    printf("\t[3] Run exercise 3 (Character Print)\n");
    printf("\t[4] Run exercise 4 (2 Dimensions Exercise)\n");
    printf("\t[5] Exit\n\n");
}
