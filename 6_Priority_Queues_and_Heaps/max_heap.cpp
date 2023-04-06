/**************************************
    @brief        Implementing MaxHeaps
***************************************/
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
int left_child(int index)
{
    int left = 2 * index + 1;
    return left;
}

/*
 * Function Name: right_child
 * Input: Index of the element
 * Output: Returns the index of the right child
 * Example Call: right_child(5)
 */
int right_child(int index)
{
    int right = 2 * index + 2;
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
        if (maxHeap[left_child(index)] > maxHeap[right_child(index)] && (maxHeap[index] < maxHeap[left_child(index)]))
        {
            swap(maxHeap[index], maxHeap[left_child(index)]);
        }
        else if (maxHeap[left_child(index)] < maxHeap[right_child(index)] && (maxHeap[index] < maxHeap[right_child(index)]))
        {
            swap(maxHeap[index], maxHeap[right_child(index)]);
        }
        else
        {
            break;
        }
    }
}

/*
 * Function Name: siftDown
 * Input: Takes the array, current size of array, and index of element
 * Output: None
 * Logic: This function shifts the element up the heap to its correct position
 * Example Call: SiftDown(maxHeap, 5, &temp)
 */
void siftUp(int maxHeap[], int index)
{
    while (index >= 1 && maxHeap[index] > maxHeap[parent(index)])
    {
        swap(maxHeap[index], maxHeap[parent(index)]);
        index = parent(index);
    }
}

/*
 * Function Name: extractMax
 * Input: Takes the array, and index of element
 * Output: Returns the maximum element i.e. root element of heap
 * Example Call: extractMax(maxHeap, 5)
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
 * Function Name: insert
 * Input: Takes the array, element, max size by value and current size of array by reference
 * Output: None
 * Logic: This function allows us to insert an element into heap
 * Example Call: insert(maxHeap, max_size, &curr_size, element)
 */
void insert(int maxHeap[], int max_size, int *n, int element)
{
    if (*n < max_size)
    {
        maxHeap[*n] = element;
        siftUp(maxHeap, *n);
        (*n)++;
    }
}

int main()
{
    int max_size, curr_size = 0;
    cout << "Please enter the total number of elements: ";
    cin >> max_size;
    int maxHeap[max_size] = {0};

    for (int i = 0; i < max_size; i++)
    {
        int element;
        cin >> element;
        insert(maxHeap, max_size, &curr_size, element);
    }

    int max;
    for (int i = 0; i < max_size; i++)
    {
        max = extractMax(maxHeap, &curr_size);
        cout << max << " ";
    }
}
/*
Analysis: The above algorithm runs in O(nlog(n)) 
*/