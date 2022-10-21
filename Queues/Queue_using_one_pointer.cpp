/* Here , we are implementing a queue using arrays , by using a single pointer only */
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
// end of function

/* to insert an element to the queue*/
void Queue ::dequeue()
{
    if (rear == &queue[0])
    {
        cout << queue[0] ;
        rear == NULL ;
    }
    if (!isEmpty())
    {
        cout << queue[0] << "\n";

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
        cout << "The queue is empty!";
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

int main()
{
    class Queue Queue1; // creating an object Queue1 of class Queue
    // Queue1.enqueue(34);
    // Queue1.enqueue(55);
    // Queue1.enqueue(10);
    Queue1.enqueue(99);
    // Queue1.display();
    Queue1.dequeue();
    // Queue1.dequeue();
    Queue1.display();

    return 0;
}
// end of main
