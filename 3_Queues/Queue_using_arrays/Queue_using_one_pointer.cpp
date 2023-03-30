/* Here , we are implementing a queue using arrays , by using a single pointer only
Insertion - O(1)
Deletion - O(n)
The drawback of using only a single pointer is that deletion takes O(n) time*/

#include <iostream>
#define MAX_SIZE 10

using namespace std;

class Queue
{
private:
    int queue[MAX_SIZE];
    int *rear = NULL; // initially , the pointer points to NULL

public:
    void enqueue(int element);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

/* to insert an element to the queue*/
void Queue ::enqueue(int element)
{
    if (!isFull()) //insert element only if queue is not full
    {
        if (rear == NULL) // if the queue is empty , and the element is first to be inserted
        {
            rear = queue; // points to the first element in queue
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
// end of function

/* to insert an element to the queue*/
void Queue ::dequeue()
{
    if (rear == &queue[0]) //considering the case if only one element is present
    {
        cout << queue[0] << "\n";
        rear = NULL;
    }
    else if (!isEmpty()) //we check if queue is not empty
    {
        cout << queue[0] << "\n"; //print the first element i.e. 0th index in array

        for (int i = 0; &queue[i] < rear; i++) // here , we go till the second last element of queue
        {
            queue[i] = queue[i + 1];
        }

        rear--; // decrementing the pointer to previous position
    }
    else
    {
        cout << "The queue is empty!\n";
    }
}
// end of function

/*to display the entire queue*/
void Queue ::display()
{
    if (rear != NULL)
    {
        cout << "The elements of queue are : ";
        for (int i = 0; &queue[i] <= rear; i++) // here , we print the element in queue till address of queue's last element matches with address at which rear points
        {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "The queue is empty!\n";
    }
}
// end of function

// returns true if queue is empty. We generally use this function in dequeue() to check during deletion
bool Queue ::isEmpty()
{
    if (rear == &queue[0])
    {
        rear = NULL;
        return false; // we return false since the queue had 1 element left and is not yet empty
    }
    else if (rear == NULL)
    {
        return true;
    }
    else
    {
        return false; // for all other cases , queue is not empty
    }
}
// end of function

// returns true if queue is full. We generally use this function in dequeue() to check during deletion
bool Queue ::isFull()
{
    if (rear == &queue[MAX_SIZE - 1])
    {
        return true; // we return true since the rear already points at last element and there is no space ahead
    }
    else
    {
        return false; // for all other cases , queue is not empty
    }
}
// end of function

int main()
{
    class Queue Queue1; // creating an object Queue1 of class Queue

    Queue1.enqueue(34);
    Queue1.enqueue(55);
    Queue1.enqueue(10);
    Queue1.display();
    Queue1.dequeue();
    Queue1.display();
    Queue1.dequeue();
    Queue1.display();
    Queue1.dequeue();
    Queue1.display();

    return 0;
}
// end of main
//end of program