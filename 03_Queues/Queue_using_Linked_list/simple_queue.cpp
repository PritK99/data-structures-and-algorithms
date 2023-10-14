/*******************************************************
    @brief        Implementing queue using a linked list
********************************************************/

#include <iostream>

using namespace std;

void enqueue(int element);
void display();

struct Node
{
    int data;
    class Node *next; // next is a pointer of type Node which points towards the next Node
};
/*initially both the pointers are NULL*/
struct Node *front = NULL;
struct Node *rear = NULL;

/*
 * Function Name: enqueue
 * Input: Integer element which is to be inserted
 * Output: None
 * Logic: This function allows us to insert an element in queue
 * Example Call: enqueue(5)
 */
void enqueue(int element)
{
    Node *temp = (Node *)malloc(sizeof(Node)); // dynamic allocation of memory
    if (temp == NULL)
    {
        cout << "Queue is full";
    }
    else if (front == NULL) // or rear == NULL, both conditions work
    {
        front = rear = temp;
        temp->data = element;
        temp->next = NULL;
    }
    else
    {
        rear->next = temp; // the next of the rear node should point at new node temp
        temp->data = element;
        temp->next = NULL;
        rear = temp; // rear should point to the new node formed
    }
}

/*
 * Function Name: dequeue
 * Input: None
 * Output: Returns the first element of queue
 * Logic: This function allows us to remove the first element of queue
 * Example Call: dequeue()
 */
void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty!";
    }
    else
    {
        cout << front->data << "\n";

        Node *temp = front;
        front = front->next;
        delete temp; // Deallocating the memory given to node
    }
}

/*
 * Function Name: display
 * Input: None
 * Output: Prints all the elements in the queue
 * Logic: This function allows us to print the elements currently in queue
 * Example Call: display()
 */
void display()
{
    Node *temp = front;
    if (front == NULL)
    {
        cout << "Queue is empty!";
    }
    else if (front == rear) // incase of only one element in queue
    {
        cout << "The elements in queue are : " << front->data ;
        struct Node *front = NULL;
        struct Node *rear = NULL;
    }
    else
    {
        cout << "The elements in queue are : ";
        while (temp != NULL)
        {
            cout << temp->data << " "; // prints data in all nodes
            temp = temp->next;
        }
    }

    cout << "\n";
}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();

    return 0;
}
