#include <stdio.h>
#include <stdlib.h>

//defining chain structure to hold name and value
struct list{
    int val;
    char* name;
    struct list* next;
};

//simple hash function which assigns value as per last digit in number
int hash(int key)
{
    return key%10;
}

void setKey(int key, char* name, struct list* hashmap[10])
{
    int hashVal = hash(key);
    if (hashmap[hashVal] == NULL)
    {
        hashmap[hashVal] = (struct list *)malloc(sizeof(struct list));
        hashmap[hashVal]->val = key;
        hashmap[hashVal]->name = name;
        hashmap[hashVal]->next = NULL;
    }
    else
    {
        int isFound = 0;
        struct list *chain = hashmap[hashVal];
        while(chain != NULL)
        {
            if (chain->val == key)
            {
                isFound = 1;
                chain->name = name;
                break;
            }
            chain = chain->next;
        }
        if (isFound == 0)
        {
            chain = (struct list *)malloc(sizeof(struct list));
            chain->val = key;
            chain->name = name;
            chain->next = NULL;
        }
    }
}

void GetKey(int key, struct list* hashmap[10])
{
    int hashVal = hash(key);
    if (hashmap[hashVal] == NULL)
    {
        printf("Value Not Found\n");
    }
    else
    {
        int isFound = 0;
        struct list *chain = hashmap[hashVal];
        while(chain != NULL)
        {
            if (chain->val == key)
            {
                isFound = 1;
                printf("%s\n", chain->name);
                break;
            }
            chain = chain->next;
        }
        if (isFound == 0)
        {
            printf("Value Not Found\n");
        }
    }
}

int main()
{
    struct list* hashmap[10];

    //initialize all pointers as NULL
    for (int i = 0 ; i < 10 ; i++)
    {
        hashmap[i] = NULL;
    }

    setKey(0, "Orange", hashmap);
    setKey(9, "Apple", hashmap);
    setKey(0, "Custurd Apple", hashmap);
    setKey(5, "Mango", hashmap);

    GetKey(0, hashmap);
    GetKey(1, hashmap);
    GetKey(5, hashmap);
    GetKey(9, hashmap);

    return 0;
}