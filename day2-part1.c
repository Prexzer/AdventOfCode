#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int i, lower, upper, count = 0;
    short passwords = 0;
    char *s, letter;
    FILE *ifp = fopen("day2.txt", "r");

    s = malloc(sizeof(char)*200);

    // EX: 2-3 a: jcaaodia -> VALID
    while (fscanf(ifp, "%d-%d %c: %s", &lower, &upper, &letter, s) != EOF)
    {
        // loops through the string counting when letter is found
        for (i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == letter)
                count++;
            
            // if it exceeds upper just stop
            if (count > upper)
                break;
        }

        // checks if the number of letters found matches the range
        if (count >= lower && count <= upper)
            passwords++;

        count = 0;
    }

    printf("Number of valid passwords: %d\n", passwords);
}