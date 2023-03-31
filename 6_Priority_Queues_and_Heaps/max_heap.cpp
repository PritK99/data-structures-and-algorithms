#include <iostream>
#include <algorithm>

using namespace std;

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

int left_child(int index)
{
    int left = 2 * index + 1;
    return left;
}

int right_child(int index)
{
    int right = 2 * index + 2;
    return right;
}

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

void siftUp(int maxHeap[], int index)
{
    while (index >= 1 && maxHeap[index] > maxHeap[parent(index)])
    {
        swap(maxHeap[index], maxHeap[parent(index)]);
        index = parent(index);
    }
}

int extractMax(int maxHeap[], int *n)
{
    int temp = maxHeap[0];
    (*n)--;
    maxHeap[0] = maxHeap[(*n)]; 
    siftDown(maxHeap, 0, n);
    return temp;
}

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