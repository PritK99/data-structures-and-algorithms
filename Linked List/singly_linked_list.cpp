#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next; // pointer which points at the next node
};

struct Node *head = NULL; // This pointer always points at the first node

/*This function is used to insert a node at the end of linked list*/
void insert(int element)
{

    if (head == NULL)
    {
        Node *temp = (Node *)malloc(sizeof(Node)); // inserting the node by creating memory dynamically
        head = temp;
        head->data = element;
        head->next = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next; // traverse the list untill you find a node whose next is null i.e. is the last node
        }
        temp->next = (Node *)malloc(sizeof(Node)); // inserting the node by creating memory dynamically

        if (temp == NULL)                          // to check if there is space in heap memory
        {
            cout << "Linked List is full\n";
        }
        else
        {
            temp->data = element ;
            temp->next = NULL ;
        }
    }
}
// end of function

void remove()
{
    if (head == NULL) // if there is no element in list OR if head pointer becomes larger than tail pointer
    {
        cout << "The Linked List is empty\n";
    }
    else
    {
        Node *temp = head; // creating a temporary traversing pointer
        while (temp->next != NULL)
        {
            temp = temp->next; // traverse the list untill you find a node whose next is null i.e. is the last node
        }
        free(temp);
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "The linked list is empty\n" ;
    }
    else 
    {
        cout << "The elements of Linked List are : " ;
        Node *temp = head; // creating a temporary traversing pointer
        while (temp->next != NULL)
        {
            cout << temp->data << " " ;
            temp = temp->next; // traverse the list untill you find a node whose next is null i.e. is the last node
        }
        cout << "\n" ;
    }
}

int main()
{
    insert(29) ;
    insert(55) ;
    insert(63) ;
    cout << head->next->data  ;
    display() ;
    // remove() ;
    // display() ;
    // remove() ;
    // display() ;
    // remove() ;
    // display() ;

}