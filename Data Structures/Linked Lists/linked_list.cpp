/******************************************************************
    @brief        Implementing single linked list with tail pointer
*******************************************************************/
#include <iostream>
using namespace std;

/*
 * Class Name: Node
 * Description: Represents a node in the linked list.
 * Contains data and a pointer to the next node.
 */
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

/*
 * Class Name: LinkedList
 * Description: Implements a singly linked list with various operations.
 */
class LinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL; 

    // Operations over a linked list
    void PushFront(int data);
    void PopFront();
    int TopFront();
    void PushBack(int data);
    void PopBack();
    int TopBack();
    void AddBefore(int data, int key);
    void Print();
    void Remove(int data);
};

/*
 * Function Name: PushFront
 * Input: Integer data to be inserted at the front of the list
 * Output: None
 * Logic: Adds a new node with the given data to the front of the list.
 * Example Call: PushFront(3)
 */
void LinkedList::PushFront(int data)
{
    if (head == NULL)
    {
        head = new Node(data);  // Create a new node if list is empty
        tail = head;  // Set tail to head since it's the only node
    }
    else
    {
        Node *temp = head;  // Store current head
        head = new Node(data);  // Create a new node
        head->next = temp;  // Set the next of new head to the old head
    }
}

/*
 * Function Name: PopFront
 * Input: None
 * Output: None
 * Logic: Removes the node at the front of the list.
 * Example Call: PopFront()
 */
void LinkedList::PopFront()
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;  // List is empty
        return;
    }
    else
    {
        Node *temp = head;  // Store the current head
        head = head->next;  // Move head to the next node
        delete temp;  // Free the memory of the old head

        if (head == NULL)
        {
            tail = NULL;  // If the list is now empty, set tail to NULL
        }
    }
}

/*
 * Function Name: TopFront
 * Input: None
 * Output: Integer value of the data at the front node
 * Logic: Returns the data from the front node if it exists.
 * Example Call: TopFront()
 */
int LinkedList::TopFront()
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;  // List is empty
        return -1;
    }
    else
    {
        return head->data;  // Return the data at the head node
    }
}

/*
 * Function Name: PushBack
 * Input: Integer data to be inserted at the end of the list
 * Output: None
 * Logic: Adds a new node with the given data to the end (tail) of the list.
 * Example Call: PushBack(7)
 */
void LinkedList::PushBack(int data)
{
    if (head == NULL)
    {
        head = new Node(data);  // Create a new node if list is empty
        tail = head;  // Set tail to head since it's the only node
    }
    else
    {
        tail->next = new Node(data);  // Link the new node to the current tail
        tail = tail->next;  // Move tail to the newly created node
    }
}

/*
 * Function Name: PopBack
 * Input: None
 * Output: None
 * Logic: Removes the node at the end (tail) of the list.
 * Example Call: PopBack()
 */
void LinkedList::PopBack()
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;  // List is empty
        return;
    }
    else
    {
        Node* temp = head;
        if (temp->next == NULL)
        {
            head = NULL;  // If only one node, set head and tail to NULL
            tail = NULL;
            return;
        }
        while(temp->next->next != NULL)  // Traverse to the second-last node
        {
            temp = temp->next;
        }
        tail = temp;  // Set tail to the second-last node
        temp = temp->next;  // Store the last node
        tail->next = NULL;  // Remove the link to the last node
        free(temp);  // Free memory of the last node
    }
}

/*
 * Function Name: TopBack
 * Input: None
 * Output: Integer value of the data at the last node
 * Logic: Returns the data from the tail node if it exists.
 * Example Call: TopBack()
 */
int LinkedList::TopBack()
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;  // List is empty
        return -1;
    }
    else
    {
        return tail->data;  // Return the data at the tail node
    }
}

/*
 * Function Name: AddBefore
 * Input: Integer data to be added and a key to find before which node to add
 * Output: None
 * Logic: Adds a node with the given data before the node with the specified key.
 * Example Call: AddBefore(4, 5)
 */
void LinkedList::AddBefore(int data, int key)
{
    if (head == NULL)
    {
        cout << "Key not found!" << endl;  // List is empty
    }
    else
    {
        if (head->data == key)
        {
            PushFront(data);  // If the key is the head, add at the front
            return;
        }

        Node* temp = head;
        bool flag = 0;
        while (temp->next != NULL)
        {
            if (temp->next->data == key)
            {
                Node* temp2 = temp->next;  // Store the node with the key
                temp = new Node(data);  // Create a new node with the data
                temp->next = temp2;  // Set the new node's next to the node with the key
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag == 0)
        {
            cout << "Key not found!" << endl;  // Key not found
        }
    }
}

/*
 * Function Name: Print
 * Input: None
 * Output: None
 * Logic: Prints the entire linked list.
 * Example Call: Print()
 */
void LinkedList::Print()
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;  // List is empty
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";  // Print data of each node
            temp = temp->next;
        }
        cout << "NULL" << endl;  // End of list
    }
}

/*
 * Function Name: Remove
 * Input: Integer key to remove the node with the given key
 * Output: None
 * Logic: Removes the node containing the specified key from the list.
 * Example Call: Remove(5)
 */
void LinkedList::Remove(int key)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;  // List is empty
    }
    else if (head->data == key)
    {
        PopFront();  // If the key is at the front, remove it
    }
    else if (tail->data == key)
    {
        PopBack();  // If the key is at the back, remove it
    }
    else
    {
        bool flag = 0;
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->data == key)
            {
                flag = 1;
                Node *p = temp->next;
                temp->next = temp->next->next;  // Link the previous node to the next node
                free(p);  // Free memory of the removed node
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (flag == 0)
        {
            cout << "Key Not Found" << endl;  // Key not found
        }
    }
}

/*
 * Function Name: main
 * Input: None
 * Output: None
 * Logic: Demonstrates the usage of the LinkedList class functions.
 */
int main()
{
    LinkedList L;

    L.PushBack(7);
    L.Print();
    L.PushFront(5);
    L.Print();
    L.AddBefore(3, 5);
    L.Print();
    L.Remove(5);
    L.Print();
    L.AddBefore(7, 6);
    L.Print();
    L.PopBack();
    L.Print();
    int x = L.TopFront();
    cout << "Current top element: " << x << endl;
    L.PopFront();
    L.Print();
    return 0;
}