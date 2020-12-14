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

    // if it full it exits
    exit(0);
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
    int num, search, key, *hash, *storage, index;
    int i, j;
    short count = 0;
    FILE *ifp = fopen("day1.txt", "r");

    // create a hash array
    hash = calloc(SIZE, sizeof(int));

    storage = malloc(sizeof(int)*SIZE);

    while (fscanf(ifp, "%d", &num) != EOF)
    {
        // store the numbers in an array
        storage[count] = num;
        count++;

        // hash them into to hashTable
        key = hashFunction(num);
        hashInsert(hash, num, key);
    }

    for (i = 0; i < count; i++)
    {
        for (j = i+1; j < count; j++)
        {
            search = SUM - storage[i] - storage[j];

            if (search < 0)
                continue;

            key = hashFunction(search);
            index = hashSearch(hash, search, key);

            if (index != FAIL)
                break;
        }

        if (index != FAIL)
            break;
    }

    // if statement to check the loop finishes and the numbers do match to 2020
    if (index == FAIL)
        printf("No numbers found.\n");

    else
    {
        printf("The answers are %d, %d, and %d\n", search, storage[i], storage[j]);
        printf("Multiplied together they are: %d\n", search * storage[i] * storage[j]);
    }
    
}