/* Here , we are implementing a queue using Linked list
Insertion - O(1)
Deletion - O(1)*/

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

void enqueue(int element)
{
    Node *temp = (Node *)malloc(sizeof(Node)); // dynaminc allocation of memory
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
        rear->next = temp; // the next of the last / rear node should point at new node temp
        temp->data = element;
        temp->next = NULL;
        rear = temp; // rear should point to the new node formed
    }
}

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
