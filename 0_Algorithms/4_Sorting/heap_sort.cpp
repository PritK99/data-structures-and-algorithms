/***************************************
    @brief        Implementing Heap Sort
****************************************/
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Function Name: parent
 * Input: Index of the element
 * Output: Returns the index of parent
 * Example Call: parent(5)
 */
int parent(int index)
{
    int parent = 0;
    if (index % 2 == 0)
    {
        parent = (index - 1) / 2;
    }
    else
    {
        parent = index / 2;
    }

    return parent;
}

/*
 * Function Name: left_child
 * Input: Index of the element
 * Output: Returns the index of the left child
 * Example Call: left_child(5)
 */
int left_child(int index, int *n)
{
    int left = 2 * index + 1;
    if (left >= *n)
    {
        return -1;
    }
    return left;
}

/*
 * Function Name: right_child
 * Input: Index of the element
 * Output: Returns the index of the right child
 * Example Call: right_child(5)
 */
int right_child(int index, int *n)
{
    int right = 2 * index + 2;
    if (right >= *n)
    {
        return -1;
    }
    return right;
}

/*
 * Function Name: siftDown
 * Input: Takes the array, current size of array, and index of element
 * Output: None
 * Logic: This function shifts the element down the heap to its correct position
 * Example Call: SiftDown(maxHeap, 5, &temp)
 */
void siftDown(int maxHeap[], int index, int *n)
{
    while (1)
    {
        if (maxHeap[left_child(index, n)] > maxHeap[right_child(index, n)] && (maxHeap[index] < maxHeap[left_child(index, n)]) && left_child(index, n) != -1)
        {
            swap(maxHeap[index], maxHeap[left_child(index, n)]);
            index = left_child(index, n);
        }
        else if (maxHeap[left_child(index, n)] < maxHeap[right_child(index, n)] && (maxHeap[index] < maxHeap[right_child(index, n)]) && right_child(index, n) != -1)
        {
            swap(maxHeap[index], maxHeap[right_child(index, n)]);
            index = right_child(index, n);
        }
        else
        {
            break;
        }
    }
}

/*
 * Function Name: extractMax
 * Input: Takes the array, and index of element
 * Output: None
 * Logic: This function shifts the element up the heap to its correct position
 * Example Call: SiftUp(maxHeap, 5)
 */
int extractMax(int maxHeap[], int *n)
{
    int temp = maxHeap[0];
    (*n)--;
    maxHeap[0] = maxHeap[(*n)];
    siftDown(maxHeap, 0, n);
    return temp;
}

/*
 * Function Name: extractMax
 * Input: Takes the array, and size of array by reference
 * Output: None
 * Logic: This function creates heap out of given array without taking any extra space
 * Example Call: Heapify(maxHeap, max_size)
 */
void Heapify(int maxHeap[], int *n)
{
    for (int i = (*n) / 2; i >= 0; i--)
    {
        siftDown(maxHeap, i, n);
    }
}

int main()
{
    int max_size, temp = 0;
    cout << "Please enter the total number of elements: ";
    cin >> max_size;
    temp = max_size;
    int maxHeap[max_size] = {0};

    for (int i = 0; i < max_size; i++)
    {
        cin >> maxHeap[i];
    }

    //Creating heap from the given array
    Heapify(maxHeap, &max_size);

    //Sorting
    for (int i = 0; i < temp; i++)
    {
        int element;
        element = extractMax(maxHeap, &max_size);
        maxHeap[max_size] = element;
    }

    for (int i = 0; i < temp; i++)
    {
        cout << maxHeap[i] << " ";
    }
}
/*
Analysis: The above algorithn runs in O(nlog(n))
*/