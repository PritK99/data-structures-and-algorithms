/*******************************************************************
    @brief        Implementing queue using a array and a two pointer
********************************************************************/
#include <iostream>
#define MAX_SIZE 10
using namespace std;

class Queue
{
private:
    int queue[MAX_SIZE];
    int *rear = NULL;
    int *front = NULL; // initially , the pointers points to NULL

public:
    void enqueue(int element);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

/*
 * Function Name: enqueue
 * Input: Integer element which is to be inserted
 * Output: None
 * Logic: This function allows us to insert an element in queue
 * Example Call: enqueue(5)
 */
void Queue ::enqueue(int element)
{
    if (!isFull()) // insert element only if queue is not full
    {
        if (rear == NULL) // if the queue is empty , and the element is first to be inserted
        {
            rear = queue; // points to the first element in queue
            front = queue;
            queue[0] = element;
        }
        else
        {
            rear++;          // increment the pointer to next position
            *rear = element; // change the value of next position
        }
    }
    else
    {
        cout << "queue is full!\n";
    }
}

/*
 * Function Name: dequeue
 * Input: None
 * Output: Returns the first element of queue
 * Logic: This function allows us to remove the first element of queue
 * Example Call: dequeue()
 */
void Queue ::dequeue()
{
    if (!isEmpty()) // we check if queue is not empty
    {
        cout << *front << "\n";
        front++; // incrementing the front the pointer to previous position
        // for dequeue , we first delete the element to which the front is pointing , then we increment front
    }
    else
    {
        cout << "The queue is empty!\n";
    }
}

/*
 * Function Name: display
 * Input: None
 * Output: Prints all the elements in the queue
 * Logic: This function allows us to print the elements currently in queue
 * Example Call: display()
 */
void Queue ::display()
{
    if (!isEmpty())
    {
        cout << "The elements of queue are : ";
        for (int i = 0; front + i <= rear; i++) // here , we print the element in queue till address of queue's last element matches with address at which rear points
        {
            cout << *(front + i) << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "The queue is empty!\n";
    }
}

/*
 * Function Name: isFull
 * Input: None
 * Output: Returns a boolean true if the queue is full
 * Logic: This function allows us to check if the queue is full
 * Example Call: isFull()
 */
bool Queue ::isFull()
{
    if (rear >= &queue[MAX_SIZE - 1])
    {
        return true; // we return false since the queue had 1 element left and is not yet empty
    }
    else
    {
        return false; // for all other cases , queue is not empty
    }
}

/*
 * Function Name: isEmpty
 * Input: None
 * Output: Returns a boolean true if the queue is empty
 * Logic: This function allows us to check if the queue is empty
 * Example Call: isEmpty()
 */
bool Queue ::isEmpty()
{
    if (rear < front || rear == NULL) // when the queue is empty , ether the front pointer is ahead of the rear pointer , or the rear pointer is null
    {
        return true;
    }
    else
    {
        return false; // for all other cases , queue is not empty
    }
}

int main()
{
    class Queue Queue1; // creating an object Queue1 of class Queue

    Queue1.enqueue(34);
    Queue1.enqueue(55);
    Queue1.enqueue(10);
    Queue1.display();
    // Queue1.dequeue();
    // Queue1.display();
    // Queue1.dequeue();
    // Queue1.display();
    // Queue1.dequeue();
    // Queue1.display();

    return 0;
}
