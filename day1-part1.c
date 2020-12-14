#include <stdio.h>
#include <stdlib.h>

#define SUM 2020
#define SIZE 991
#define FAIL -91234


int hashFunction(int num)
{
    return num * 23 + 80;
}

void hashInsert(int *hash, int num, int index)
{
    int i = 0;

    // Quadratic probing collision policy
    // stops when reach same index we started at
    while(((index + i * i) % SIZE) != index)
    {
        // check index --> key + i^2 modded by table size
        if (hash[(index + i * i) % SIZE] == 0)
        {
            hash[(index + i * i) % SIZE] = num;
            return;
        }

        i++;
    }
}

int hashSearch(int *hash, int num, int index)
{
    int i = 0;

    // Quadratic probing collision policy
    while(((index + i * i) % SIZE) != index)
    {
        
        // check index --> key + i^2 modded by table size
        if (hash[(index + i * i) % SIZE] == 0)
            return FAIL;

        else if (hash[(index + i * i) % SIZE] == num)
            return (index + i * i) % SIZE;

        i++;
    }

    // if it exits the loop it failed
    return FAIL;
}

void main(void)
{
    int num, search, key, *hash, index;
    FILE *ifp = fopen("day1.txt", "r");

    // create a hash array
    hash = calloc(SIZE, sizeof(int));

    while (fscanf(ifp, "%d", &num) != EOF)
    {
        // subtract num from 2020
        search = SUM - num;

        // get the hash for the search
        key = hashFunction(search);

        // check to see if search is in the hash
        index = hashSearch(hash, search, key);
        
        if (index != FAIL)
            break;

        // insert the new num into the hash array 
        else
        {
            // hash the num then add it to the hashtable
            key = hashFunction(num);
            hashInsert(hash, num, key);
        }
    }

    // if statement to check the loop finishes and the numbers do match to 2020
    if (index == FAIL)
        printf("No numbers found.\n");

    else
    {
        printf("The answers are %d, and %d\n", num, search);
        printf("Multiplied together they are: %d\n", num*search);
    }
    
}