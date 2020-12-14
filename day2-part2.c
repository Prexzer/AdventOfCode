#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int i, lower, upper, count = 0;
    short passwords = 0;
    char *s, letter;
    FILE *ifp = fopen("day2.txt", "r");

    s = malloc(sizeof(char)*200);

    while (fscanf(ifp, "%d-%d %c: %s", &lower, &upper, &letter, s) != EOF)
    {
        // if the first spot is equal and second is not
        if (s[lower-1] == letter && s[upper-1] != letter)
            passwords++;
        
        // if the first spot is not equal and the second is equal
        else if (s[lower-1] != letter && s[upper-1] == letter)
            passwords++;

    }

    printf("Number of valid passwords: %d\n", passwords);
}