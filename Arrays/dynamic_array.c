/***********************************************************
    @brief        Implementing dynamic arrays (Vectors) in C
*************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector
{
    int capacity;
    int size;
    int *arr;
} Vector;

/*
 * Function Name: PushBack
 * Input: Requires The element, pointer to array, capacity and size of object
 * Output: returns the modified array after insertion
 * Logic: Inserts an element to array and resizes the array if required
 * Example Call: PushBack(num, v.arr, &v.capacity, &v.size)
 */
int *PushBack(int element, int *arr, int *capacity, int *size)
{
    if (*size == *capacity) // Resizing the array is it is full
    {
        *capacity *= 2;
        int *temp = (int *)malloc(sizeof(int) * (*capacity));

        for (int i = 0; i < *size; i++)
        {
            temp[i] = arr[i];
        }

        free(arr);
        arr = temp;
    }
    arr[*size] = element;
    (*size)++;

    return arr;
}

int main()
{
    Vector v;       // Creating an object of struct Vector
    v.capacity = 2; // Initializing the values for object
    v.size = 0;
    v.arr = (int *)malloc(v.capacity * sizeof(int));

    while (1)
    {
        printf("Please enter 1 to insert an element, 2 to display an element and 3 to quit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            int num;
            printf("Please enter the element: ");
            scanf("%d", &num);
            v.arr = PushBack(num, v.arr, &v.capacity, &v.size);
        }
        else if (choice == 2)
        {
            int index;
            printf("Enter the index: ");
            scanf("%d", &index);
            if (index < 0 || index >= v.size)
            {
                printf("Index is out of bounds\n");
                continue;
            }
            printf("The element is: %d", v.arr[index]);
        }
        else
        {
            break;
        }
    }
    return 0;
}

/*
Analysis: The above code runs in O(1) for inserting an element and displaying an element, using amortized analysis.
*/